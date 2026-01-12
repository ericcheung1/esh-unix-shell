#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include "shell_core.h"
#include "utils.h"

int main(int argc, char *argv[]) {
    esh_print_title();
    esh_loop();

    return EXIT_SUCCESS;
}
