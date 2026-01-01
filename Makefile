shell: main.c builtins.c execute.c get_args.c
	mkdir -p bin
	gcc -Wall -std=c99 -o bin/shell main.c builtins.c execute.c get_args.c