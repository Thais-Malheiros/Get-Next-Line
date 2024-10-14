# Get Next Line
## Reading a line from a fd is not as easy as it seems

![gnl_icon](https://github.com/Thais-Malheiros/Get-Next-Line/blob/main/gnl.png)

## Description

The get_next_line project is a C function that reads a line from a specified file descriptor. It is designed to handle repeated calls, allowing you to read a text file one line at a time, whether from a regular file or from standard input.

## Prototype

`char *get_next_line(int fd);`

## Parameters

fd: the file descriptor to read from.

## Return Value

• Returns the read line as a string, including the terminating newline character (\n), except when reaching the end of the file that does not end with a newline.
• Returns `NULL` if there is nothing else to read or if an error occurs.

## External Functions Allowed

• `read`

• `malloc`

• `free`

## How to use this project

1) Clone the Repository

`git clone https://github.com/Chrystian-Natanael/Get_next_line.git`

2) Include the Header File

In your main file, include the header file to gain access to the `get_next_line()` function:

`#include "get_next_line.h"`

3) Call the function

To read a line, call the function in your main file, passing a file descriptor. Ensure you have a variable of type char * to store the return value (the read line):

`char *line;`

`line = get_next_line(fd);`

Example of a Main File

Make sure to have a `test.txt` file at the root of your repository. Below is an example of how your main file might look:

```
#include "get_next_line.h" // for get_next_line
#include <stdio.h> // for printf
#include <fcntl.h> // for open

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY); // Open the file
    line = get_next_line(fd); // Read the first line
    printf("%s\n", line); // Print the first line
    free(line); // Free the allocated memory for the line
    close(fd); // Close the file descriptor
    return 0;
}




