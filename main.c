#include <stdio.h>
#include <stdlib.h>

#include "execute.h"
#include "get_args.h"
#include "builtins.h"

void esh_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = esh_read_line();
        args = esh_split_line(line);
        status = esh_execute(args);

        free(line);
        free(args);
    } while (status);
}

int main(int argc, char *argv[]) {

    esh_loop();

    return EXIT_SUCCESS;
}