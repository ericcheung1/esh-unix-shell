#ifndef SHELL_CORE_H
#define SHELL_CORE_H_H

int esh_launch(char** args);

int esh_execute(char** args);

void esh_loop(void);

#endif