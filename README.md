# esh Unix Shell

This project is a basic implementation of a Unix Shell in C. It is based on Stephen Brennan's tutorial: https://github.com/brenns10/lsh & https://brennan.io/2015/01/16/write-a-shell-in-c/. This version separates Stephen's versiion into source .c and header .h files along with a Makefile for easier compilation. There are many limitations to this simple shell including:

* Only whitespace as separators 
* Arguments can only be written on one line
* No quoting arguments or escaping whitespaces


## How to use

Clone this repo then use the `make` command in the terminal. Then the compiled binary will appear in a `bin/` folder, use `./bin/shell` to start the program.

## Future additions

This project may be used to learn more about operating systems and systems programming. More robust shell features such as quotable arguments and pipes maybe additions in the future.