#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(void);
void close_fd(int fd);

/**
 * allocate_buffer - Allocates 1024 bytes for a buffer.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(void)
{
	char *buffer;

	buffer = malloc(1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
		exit(EXIT_FAILURE);
	}

	return (buffer);
}

/**
 * close_fd - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc_copy: The number of arguments supplied to the program.
 * @argv_copy: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc_copy, char *argv_copy[])
{
	int source_fd, target_fd, read_count, write_count;
	char *data_buffer;

	if (argc_copy != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	data_buffer = allocate_buffer();
	source_fd = open(argv_copy[1], O_RDONLY);
	if (source_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv_copy[1]);
		free(data_buffer);
		exit(98);
	}

	target_fd = open(argv_copy[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (target_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv_copy[2]);
		free(data_buffer);
		close_fd(source_fd);
		exit(99);
	}

	do {
		read_count = read(source_fd, data_buffer, 1024);
		if (read_count == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv_copy[1]);
			free(data_buffer);
			close_fd(source_fd);
			close_fd(target_fd);
			exit(98);
		}

		write_count = write(target_fd, data_buffer, read_count);
		if (write_count == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv_copy[2]);
			free(data_buffer);
			close_fd(source_fd);
			close_fd(target_fd);
			exit(99);
		}

	} while (read_count > 0);

	free(data_buffer);
	close_fd(source_fd);
	close_fd(target_fd);

	return (EXIT_SUCCESS);
}

