bin/shell: main.c utils.c shell_core.c parse_args.c
	mkdir -p bin
	gcc -Wall -std=c99 -o bin/shell main.c utils.c shell_core.c parse_args.c