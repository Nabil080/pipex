# Pipex - Unix Pipe Implementation

## About

**Pipex** is a program that mimics the behavior of Unix pipes (`|`). It allows executing multiple commands in sequence, where the output of each command is passed as input to the next, similar to shell behavior.

## Features

- **Supports multiple pipes (`|`)**: Handles sequences of commands, not just two.
- **File Redirection**: Reads from a file and writes to another.
- **Error Handling**: Manages invalid commands and file errors.

## Dependencies

- A C compiler (`gcc` or `clang`)
- `make` (for building the project)

## Installation

Clone the repository and build the project:

```sh
git clone https://github.com/Nabil080/pipex
cd pipex
make
```

## Usage

Run Pipex with the following syntax:

```sh
./pipex infile "cmd1" "cmd2" ... "cmdN" outfile
```

This is equivalent to the shell command:

```sh
< infile cmd1 | cmd2 | ... | cmdN > outfile
```

### Example

```sh
./pipex input.txt "grep hello" "sort" "uniq" "wc -l" output.txt
```

This takes `input.txt`, filters lines containing "hello" with `grep`, sorts them with `sort`, removes duplicates with `uniq`, counts the lines using `wc -l`, and writes the result to `output.txt`.

## Cleaning Up

To remove compiled files, run:

```sh
make clean
```

To completely remove all binaries and object files:

```sh
make fclean
```
