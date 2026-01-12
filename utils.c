#include <stdio.h>
#include <unistd.h>

#include "utils.h"

// built ins

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

// other utils

void print_dir(void) {
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s", cwd);
    } else {
        perror("getwd error");
        printf("Cannot compute directory\n");
    }
}

void esh_print_title(void) {
    printf("\n");
    fputs(
    " /%%%%%%%%  /%%%%%%  /%%   /%%           /%%   /%%           /%%                  /%%%%%%  /%%                 /%% /%%\n"
    "| %%_____/ /%%__  %%| %%  | %%          | %%  | %%          |__/                 /%%__  %%| %%                | %%| %%\n"
    "| %%      | %%  \\__/| %%  | %% /%%      | %%  | %% /%%%%%%%  /%% /%%   /%%      | %%  \\__/| %%%%%%%   /%%%%%% | %%| %%\n"
    "| %%%%%   |  %%%%%% | %%%%%%%%|__/      | %%  | %%| %%__  %%| %%|  %% /%%/      |  %%%%%% | %%__  %% /%%__  %%| %%| %%\n"
    "| %%__/    \\____  %%| %%__  %%          | %%  | %%| %%  \\ %%| %% \\  %%%%/        \\____  %%| %%  \\ %%| %%%%%%%%| %%| %%\n"
    "| %%       /%%  \\ %%| %%  | %% /%%      | %%  | %%| %%  | %%| %%  >%%  %%        /%%  \\ %%| %%  | %%| %%_____/| %%| %%\n"
    "| %%%%%%%%|  %%%%%%/| %%  | %%|__/      |  %%%%%%/| %%  | %%| %% /%%/\\  %%      |  %%%%%%/| %%  | %%|  %%%%%%%| %%| %%\n"
    "|________/ \\______/ |__/  |__/           \\______/ |__/  |__/|__/|__/  \\__/       \\______/ |__/  |__/ \\_______/|__/|__/\n",
    stdout);
    printf("\n\n");
    printf("type 'help' + enter to display help text\n");
    printf("shoutout to Stephen Brennan for the shell tutorial!\n");
    printf("shoutout to Pastorjk for the ASCII art generator!\n\n");
}