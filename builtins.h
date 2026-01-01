#ifndef BUILTINS_H
#define BUILTINS_H

extern char* builtin_str[];

extern int (*builtin_func[]) (char **);

int esh_num_builtins();

int esh_cd(char** args);

int esh_help(char** args);

int esh_exit(char** args);

#endif 