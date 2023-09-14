# C - Simple Shell

# DESCRIPTION
- This simple shell project, also known as a command-line shell/a terminal shell, is a program that provides a user interface for interacting with an operating system. It allows users to execute commands and run programs by typing them as text input.
- Its main goal is to replicate the basic functionality of a traditional shell, suchas the Unix shell (e.g. Bash) or the Windows Command Prompt.
- Its allowed functions and system calls are: 
・read
・write
・open
・execve
・exit
・fflush
・fork
・free
・malloc
・getline
・isatty
・perror
・strtok
・wait
・waitpid
・etc....
- In conclusion, this simple shell will provide a user-friendly interface for interacting with an operating system, allowing users to execute commands, run programs, and automate tasks efficiently. It also serves as a fundamental building block for more advanced shell implementations and provides a deeper understanding of how command-line interfaces work.

# KEY COMPONENTS AND FEATURES:
1. Command Execution: The shell interprets user input as commands and executes them. It searches for executables in the system's directories or in specified paths.
2. Input/Output Redirection: The shell allows users to redirect input and output streams of commands. For examples, users can redirect the ouput of a command to a file or read input from a file instead of the standard input.
3. Pipelining: The shel supports connecting multiple commands together using pipes. This allows the output of one command to serve as the input for another command.
4. Command History: The shell keeps track of previously executed commands, allowing users to access and reuse them easily. It often provides navigation through command history using keyboard shortcuts or special commands.
5. Environment Variables: The shell manages environment variables, which are special variables that store information about the system or user preferences. Users can set, modify, and use environment variables within the shell.
6. Shell Scripting: The shell allows users to create and execute shell scripts - text files containing a series of shell commands. Shell scripts provide a way to automate tasks and run multiple commands in sequence.

# BASIC USAGE:
1. Launching the Shell: Open a terminal/ command prompt on your operating system. This will start the shell program and provide you with a command-line interface.
2. Entering Commands: Once the shell is launched, you can start entering commands. Simply type the desired command and press Enter. The shell will then interpret and execute the command.
3. Command Execution: The shell will execute the command you entered, performing the specified action. This can include running programs, manipulating files, or interacting with the operating system.
4. Command Output: After execution, the shell may display output from the command. This could be informational messages, error messages, or the results of the commands operation.
5. Command Completion: Many shells provide command completion functionality. As you type a command or a file path, you can press the Tab key to auto-complete it based on the available options. This helps to reduce typing and avoid errors.
6. Command History: Shells often keep track of the commands you have entered. You can navigate through the command history using arrow keys or specific commands, such as the `history` command. This allows you to reuse or modify previously executed commands.
7. Exiting the Shell: To exit the shell, you can use the `exit` comand or press Ctrl + D (Unix-like systems) pr Ctril + Z (Windows). This will terminate the shell and return you to the previous environment.

# ACKNOWLEDGE
・ALX Community

# AUTHORS:
・Vitaleng
・NomfundoPM

