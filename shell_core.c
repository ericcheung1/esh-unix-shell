#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "shell_core.h"
#include "parse_args.h"
#include "utils.h"

void esh_loop(void) {
    int status;

    do {
        print_dir();
        printf("%% ");
        char *line = esh_read_line();
        char **args = esh_split_line(line);
        status = esh_execute(args);

        free(line);
        free(args);
    } while (status);
}

int esh_launch(char** args) {
    int status;
    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("esh");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("esh");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int esh_execute(char** args) {
    if (args[0] == NULL) {
        return 1;
    }

    for (int i = 0; i < esh_num_builtins(); i++) {
        if (strcmp(args[0], builtin_str[i]) == 0) {
            return (*builtin_func[i])(args);
        }
    }

    return esh_launch(args);
}
