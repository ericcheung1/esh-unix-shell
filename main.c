#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include "execute.h"
#include "get_args.h"
#include "builtins.h"

void esh_loop(void);
void esh_print_title(void);
void print_dir(void);

int main(int argc, char *argv[]) {
    esh_print_title();
    esh_loop();

    return EXIT_SUCCESS;
}

void print_dir(void) {
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s", cwd);
    } else {
        perror("getwd error");
        printf("Cannot compute directory\n");
    }
}

void esh_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        print_dir();
        printf("%% ");
        line = esh_read_line();
        args = esh_split_line(line);
        status = esh_execute(args);

        free(line);
        free(args);
    } while (status);
}

void esh_print_title(void) {
    printf("\n");
    printf(
    " /$$$$$$$$  /$$$$$$  /$$   /$$           /$$   /$$           /$$                  /$$$$$$  /$$                 /$$ /$$\n"
    "| $$_____/ /$$__  $$| $$  | $$          | $$  | $$          |__/                 /$$__  $$| $$                | $$| $$\n"
    "| $$      | $$  \\__/| $$  | $$ /$$      | $$  | $$ /$$$$$$$  /$$ /$$   /$$      | $$  \\__/| $$$$$$$   /$$$$$$ | $$| $$\n"
    "| $$$$$   |  $$$$$$ | $$$$$$$$|__/      | $$  | $$| $$__  $$| $$|  $$ /$$/      |  $$$$$$ | $$__  $$ /$$__  $$| $$| $$\n"
    "| $$__/    \\____  $$| $$__  $$          | $$  | $$| $$  \\ $$| $$ \\  $$$$/        \\____  $$| $$  \\ $$| $$$$$$$$| $$| $$\n"
    "| $$       /$$  \\ $$| $$  | $$ /$$      | $$  | $$| $$  | $$| $$  >$$  $$        /$$  \\ $$| $$  | $$| $$_____/| $$| $$\n"
    "| $$$$$$$$|  $$$$$$/| $$  | $$|__/      |  $$$$$$/| $$  | $$| $$ /$$/\\  $$      |  $$$$$$/| $$  | $$|  $$$$$$$| $$| $$\n"
    "|________/ \\______/ |__/  |__/           \\______/ |__/  |__/|__/|__/  \\__/       \\______/ |__/  |__/ \\_______/|__/|__/\n"
    );
    printf("\n\n");
    printf("type 'help' + enter to display help text\n");
    printf("shoutout to Stephen Brennan for the shell tutorial!\n");
    printf("shoutout to pastorjk for the ASCII art generator!\n\n");
}
