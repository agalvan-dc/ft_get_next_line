*This project has been created as part of the 42 curriculum by agalvan-.*

# get_next_line

## Description

**get_next_line** is a project from the 42 school curriculum that challenges you to implement a function capable of reading a line from a file descriptor, one line at a time. Each successive call to `get_next_line` returns the next line from the file or standard input, making it a fundamental building block for many future projects.

The goal is to understand how static variables, file descriptors, and dynamic memory allocation work together in C, while also managing edge cases such as end-of-file, read errors, and varying buffer sizes.

**Function prototype:**
```c
char *get_next_line(int fd);
```

The function returns the next line read from the file descriptor `fd`, including the newline character `\n` if present. It returns `NULL` when there is nothing left to read or when an error occurs.

---

## Instructions

### Compilation

The project must be compiled with the following flags:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=<n> get_next_line.c get_next_line_utils.c
```

Replace `<n>` with the desired buffer size (e.g., `42`, `1`, `9999`).

### Files

The project consists of the following files:

- `get_next_line.c` — Main function implementation
- `get_next_line_utils.c` — Helper functions
- `get_next_line.h` — Header file

### Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("example.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Notes

- The `BUFFER_SIZE` macro can be overridden at compile time using `-D BUFFER_SIZE=<n>`.
- The function must work correctly for both file descriptors and standard input (`fd = 0`).
- Undefined behavior is expected if the file changes between two calls while reading is still in progress.

---

## Resources

### Documentation & References

- [man 2 read](https://man7.org/linux/man-pages/man2/read.2.html) — Linux manual page for the `read` system call
- [man 3 malloc](https://man7.org/linux/man-pages/man3/malloc.3.html) — Linux manual page for `malloc`
- [File Descriptors – Wikipedia](https://en.wikipedia.org/wiki/File_descriptor) — Overview of file descriptors
- [Static Variables in C – GeeksforGeeks](https://www.geeksforgeeks.org/static-variables-in-c/) — Guide on static variable behavior in C
- [42 Docs – Norm](https://github.com/42School/norminette) — 42's C coding standard (Norminette)

### AI Usage

Artificial intelligence (AI) was used exclusively to assist in writing this **README.md** file