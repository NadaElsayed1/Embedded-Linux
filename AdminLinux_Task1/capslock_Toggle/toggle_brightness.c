#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd;         // File descriptor for the brightness file
    char buffer[1]; // Buffer to store the brightness value

    // Read one byte from the standard input (this is the brightness value)
    // `STDIN_FILENO` is the file descriptor for standard input (usually 0)
    // `buffer` is where the read byte will be stored
    // `1` specifies the number of bytes to read
    read(STDIN_FILENO, buffer, 1);

    // Open the brightness file for writing
    // The file is located at "/sys/class/leds/input2::capslock/brightness"
    // `O_WRONLY` specifies that the file is opened for writing only
    fd = open("/sys/class/leds/input2::capslock/brightness", O_WRONLY);

    // Check if the file was successfully opened
    if (fd == -1)
    {
        perror("Failed to open brightness file"); // Print error message
        return 1;                                 // Return with error code 1
    }

    // Toggle the brightness value
    // If the current brightness is '0', set it to '1'
    // If the current brightness is '1', set it to '0'
    if (buffer[0] == '0')
    {
        buffer[0] = '1';
    }
    else
    {
        buffer[0] = '0';
    }

    // Write the new brightness value to the brightness file
    // `fd` is the file descriptor of the brightness file
    // `buffer` contains the new brightness value
    // `1` specifies the number of bytes to write
    if (write(fd, buffer, 1) != 1)
    {
        perror("Failed to write to brightness file"); // Print error message
        close(fd);                                    // Close the file before exiting
        return 1;                                     // Return with error code 1
    }

    // Close the file descriptor
    // This is important to ensure that the file is properly saved and not left open
    close(fd);

    // Return 0 to indicate successful execution
    return 0;
}
