# libasm

This project re-implements part of the standard C library functions in 64-bit assembly using Intel syntax.

## Description

The following functions are implemented:

- `strcmp`
- `strcpy`
- `strlen`
- `read`
- `write`
- `strdup`

Errors are handled appropriately for system calls, and the global errno is set when necessary using `___error` or `errno_location`.

## Requirements

- Assembler: NASM
- Compiler: GCC (for linking and testing)
- macOS or Linux

## How to Build and Test

```shell
git clone https://github.com/ryo-manba/libasm

# macOS
cd libasm/mac
make test

# linux
cd libasm/linux
make test
```
