
# Minishell

## Overview
Minishell is a C program that replicates some of the functionalities of a Unix shell. This project is part of the 42 School curriculum, and its primary goal is to understand the workings of a shell by building one from scratch.

## Features
- Basic command interpretation and execution.
- Support for built-in commands.
- Environment variable handling.
- Signal handling (e.g., `Ctrl-C`, `Ctrl-D`, `Ctrl-\`).

## Usage

### Compilation
```bash
gcc -Wall -Wextra -Werror *.c -o minishell
```

### Execution
```bash
./minishell
```

### Exiting
Type `exit` or use `Ctrl-D` to exit the shell.

## Built-in Commands
- `echo`
- `cd`
- `pwd`
- `export`
- `unset`
- `env`
- `exit`

## External Commands
Minishell can execute commands located in the system's `PATH`.

## Signal Handling
Minishell handles signals like `SIGINT` and `SIGQUIT` in a manner similar to bash.

## Notes
- Error handling and proper memory management are crucial.
- Ensure the shell is stable and can run continuously.
