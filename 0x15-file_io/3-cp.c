#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int open_source_file(const char *filename);
int open_destination_file(const char *filename);
void copy_file(int source_fd, int dest_fd);
void close_file(int fd, const char *filename);

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Return: 0 on success, or an error code on failure
 */

int main(int argc, char *argv[])
{
	int source_fd;
	int dest_fd;

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	source_fd = open_source_file(argv[1]);
	dest_fd = open_destination_file(argv[2]);

	copy_file(source_fd, dest_fd);

	close_file(source_fd, argv[1]);
	close_file(dest_fd, argv[2]);

	return (0);
}


/**
 * open_source_file - Opens the source file for reading
 * @filename: The name of the source file
 *
 * Return: The file descriptor of the opened file, or -1 on failure
 */

int open_source_file(const char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
 * open_destination_file - Opens the destination file for writing
 * @filename: The name of the destination file
 *
 * Return: The file descriptor of the opened file, or -1 on failure
 */

int open_destination_file(const char *filename)
{
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", filename);
		exit(99);
	}
	return (fd);
}

/**
 * copy_file - Copies the content of the source file to the destination file
 * @source_fd: The file descriptor of the source file
 * @dest_fd: The file descriptor of the destination file
 */

void copy_file(int source_fd, int dest_fd)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(2, "Error: Can't write to destination file\n");
			close_file(source_fd, NULL);
			close_file(dest_fd, NULL);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(2, "Error: Can't read from source file\n");
		close_file(source_fd, NULL);
		close_file(dest_fd, NULL);
		exit(98);
	}
}

/**
 * close_file - Closes a file descriptor
 * @fd: The file descriptor to close
 * @filename: The name of the file associated with the file descriptor
 */

void close_file(int fd, const char *filename)
{
	if (close(fd) == -1)
	{
		if (filename)
			dprintf(2, "Error: Can't close fd %d for file %s\n", fd, filename);
		else
			dprintf(2, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

