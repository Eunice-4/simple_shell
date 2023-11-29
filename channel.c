Please note that these are just the basic structures. 
You’ll need to implement the functions like read_line(), split_line(), 
and execute() according to your project requirements. 
Also, remember to handle errors and edge cases appropriately.

main.c: This is the entry point of your program. You should initialize your shell here, enter the shell loop, and then clean up and exit when done.

shell_loop.c: This is where the main loop of your shell will be. You should print a prompt, read a line of input, parse the line into arguments, execute the command, and then repeat.

parser.c: This is where you’ll parse the input line into a list of arguments. You can use functions like strtok to split the string into tokens.

builtin.c: This is where you’ll handle built-in commands. You should check if the command is a built-in, and if so, execute it.
