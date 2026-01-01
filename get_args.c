#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define ESH_RL_BUFSIZE 1024
#define ESH_TOK_BUFSIZE 64
#define ESH_TOK_DELIM " \t\r\n\a"

#include "get_args.h"

char* esh_read_line(void) {
    int bufsize = ESH_RL_BUFSIZE;
    int position = 0;
    char* buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = getchar();

        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;

        if (position >= bufsize) {
            bufsize += ESH_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if (!buffer) {
                fprintf(stderr, "lsh: reallocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

char** esh_split_line(char* line) {
    int bufsize = ESH_TOK_BUFSIZE;
    int position = 0;
    char** tokens = malloc(sizeof(char*) * bufsize);
    char* token;

    if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, ESH_TOK_DELIM);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += ESH_TOK_BUFSIZE;
            tokens = realloc(tokens, sizeof(char*) * bufsize);
            if (!tokens) {
                fprintf(stderr, "lsh: reallocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, ESH_TOK_DELIM);
    }

    tokens[position] = NULL;
    return tokens;
}