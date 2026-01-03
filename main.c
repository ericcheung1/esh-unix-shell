#include <stdio.h>
#include <stdlib.h>

#include "execute.h"
#include "get_args.h"
#include "builtins.h"

void esh_loop(void);
void esh_print_title(void);

int main(int argc, char *argv[]) {
    esh_print_title();
    esh_loop();

    return EXIT_SUCCESS;
}

void esh_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf(">>> ");
        line = esh_read_line();
        args = esh_split_line(line);
        status = esh_execute(args);

        free(line);
        free(args);
    } while (status);
}

void esh_print_title(void) {
    printf(" ____  ____  _  _    _  _  __ _  __  _  _    ____  _  _  ____  __    __   \n");
    printf("(  __)/ ___)/ )( \\  / )( \\(  ( \\(  )( \\/ )  / ___)/ )( \\(  __)(  )  (  )\n");
    printf(" ) _) \\___ \\) __ (  ) \\/ (/    / )(  )  (   \\___ \\) __ ( ) _) / (_/\\/ (_/\\\n");
    printf("(____)(____/\\_)(_/  \\____/\\_)__)(__)(_/\\_)  (____/\\_)(_/(____)\\____/\\____/\n");
    printf("\n\n\n");
}