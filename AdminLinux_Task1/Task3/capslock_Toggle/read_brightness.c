#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd;         // File descriptor for the brightness file
    char buffer[1]; // Buffer to store the brightness value

    // Open the brightness file for reading
    // The file is located at "/sys/class/leds/input2::capslock/brightness"
    // `O_RDONLY` specifies that the file is opened for reading only
    fd = open("/sys/class/leds/input2::capslock/brightness", O_RDONLY);

    // Check if the file was successfully opened
    if (fd == -1)
    {
        perror("Failed to open brightness file"); // Print error message
        return 1;                                 // Return with error code 1
    }

    // Read one byte from the brightness file
    // `fd` is the file descriptor of the brightness file
    // `buffer` is where the read byte will be stored
    // `1` specifies the number of bytes to read
    if (read(fd, buffer, 1) != 1)
    {
        perror("Failed to read from brightness file"); // Print error message
        close(fd);                                     // Close the file before exiting
        return 1;                                      // Return with error code 1
    }

    // Write the read brightness value to standard output
    // `STDOUT_FILENO` is the file descriptor for standard output (usually 1)
    // `buffer` contains the brightness value to write
    // `1` specifies the number of bytes to write
    if (write(STDOUT_FILENO, buffer, 1) != 1)
    {
        perror("Failed to write to stdout"); // Print error message
        close(fd);                           // Close the file before exiting
        return 1;                            // Return with error code 1
    }

    // Close the file descriptor
    // This is important to ensure that the file is properly saved and not left open
    close(fd);

    // Return 0 to indicate successful execution
    return 0;
}