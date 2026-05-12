# Get Next Line

*This project has been created as part of the 42 curriculum by yusakaki.*

## Description

The **Get Next Line** project is a fundamental exercise in C programming that focuses on implementing a function capable of reading a file descriptor line by line. This project teaches important concepts such as static variables, dynamic memory management, and efficient file I/O handling.

The main goal is to create a reusable function that reads text files sequentially, one line at a time, maintaining state between function calls using static variables.

## Instructions

### Compilation

To compile the project with a specific buffer size:

```bash
make
# or with a custom buffer size
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

### Available Make Rules

- `make` or `make all` - Compile the project and create the library
- `make clean` - Remove object files
- `make fclean` - Remove all generated files (objects and library)
- `make re` - Rebuild the project from scratch

### Usage

Include the header file in your project:

```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Algorithm Explanation

The implementation uses a **buffered reading approach** with a static variable to maintain state between function calls:

1. **Static Buffer**: A static character pointer maintains the remaining content from the last read operation.

2. **Three-Phase Process**:
   - **Read Phase**: If the buffer doesn't contain a newline, read a chunk of data (BUFFER_SIZE bytes) from the file descriptor.
   - **Extract Phase**: Extract the first complete line (up to and including the newline character).
   - **Update Phase**: Preserve any remaining data in the buffer for the next function call.

3. **Edge Cases Handling**:
   - Returns the line without a newline when reaching EOF if the file doesn't end with `\n`
   - Handles different BUFFER_SIZE values (works with any positive size)
   - Properly manages memory to avoid leaks
   - Returns NULL when nothing is left to read

4. **Advantages**:
   - Efficient memory usage through incremental reading
   - Works with any BUFFER_SIZE value
   - Maintains reading state automatically via static variables
   - Supports multiple simultaneous reads from different file descriptors (with modifications for bonus)

## Resources

- [C Dynamic Memory Allocation](https://en.cppreference.com/w/c/memory)
- [Static Variables in C](https://www.tutorialspoint.com/cprogramming/c_static_variables.htm)
- [File I/O Operations](https://pubs.opengroup.org/onlinepubs/9699919799/functions/read.html)
- [String Manipulation](https://en.cppreference.com/w/c/string/byte)

## How AI was Used

AI was **not directly used** in creating this project. This implementation was developed through:
- Manual study of the C language and system calls
- Understanding of memory management principles
- Analysis of the project requirements
- Implementation through problem-solving and testing

The project emphasizes building strong foundations through authentic learning, as per the 42 curriculum guidelines.

## Bonus Features

For the bonus part:
- Implement `get_next_line()` using only one static variable
- Support reading from multiple file descriptors simultaneously without losing track of each one's state

Create `get_next_line_bonus.c`, `get_next_line_bonus.h`, and `get_next_line_utils_bonus.c` for bonus implementations.
