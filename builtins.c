#include <stdio.h>
#include <unistd.h>

#include "builtins.h"

char* builtin_str[] = {
    "cd",
    "help",
    "exit"
};

char* builtin_explain_str[] = {
    " - change directories",
    " - display help text: you are here",
    " - exit the shell session"
};

int (*builtin_func[]) (char **) = {
    &esh_cd,
    &esh_help,
    &esh_exit
};

int esh_num_builtins() {
    return sizeof(builtin_str) / sizeof(char *); 
}

int esh_cd(char** args) {
    if (args[1] == 0) {
        fprintf(stderr, "esh: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("esh");
        }
    }
    return 1;
}

int esh_help(char** args) {
    printf("\n");
    printf("Welcome to Eric's rendition of Stephen Brennan's Unix/Unix-like Shell\n");
    printf("Type program names and arguments, and hit enter\n");
    printf("The following are built in:\n\n");

    for (int i = 0; i < esh_num_builtins(); i++) {
        printf("    ** %s", builtin_str[i]);
        printf("%s\n", builtin_explain_str[i]);
    }

    printf("\n");
    printf("Use the man command for information on other programs\n");
    printf("\n");
    return 1;
}

int esh_exit(char** args) {
    return 0;
}