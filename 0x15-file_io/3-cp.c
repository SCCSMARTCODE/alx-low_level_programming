#include <stddef.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file_name: The name of the file the buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(const char *file_name)
{
	char *file_buffer;

	file_buffer = malloc(1024);

	if (file_buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_name);
		exit(99);
	}

	return (file_buffer);
}

/**
 * close_file - Closes a file descriptor.
 * @file_desc: The file descriptor to be closed.
 * @file_name: The name of the file being closed.
 */
void close_file(int file_desc, const char *file_name)
{
	if (close(file_desc) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_desc);
		free((void *)file_name);
		exit(100);
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
	int source_file_desc, target_file_desc, read_count, write_count;
	char *data_buffer;

	if (argc_copy != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	data_buffer = create_buffer(argv_copy[2]);
	source_file_desc = open(argv_copy[1], O_RDONLY);
	if (source_file_desc == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv_copy[1]);
		free(data_buffer);
		exit(98);
	}

	target_file_desc = open(argv_copy[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (target_file_desc == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv_copy[2]);
		free(data_buffer);
		close_file(source_file_desc, argv_copy[1]);
		exit(99);
	}

	do {
		read_count = read(source_file_desc, data_buffer, 1024);
		if (read_count == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv_copy[1]);
			free(data_buffer);
			close_file(source_file_desc, argv_copy[1]);
			close_file(target_file_desc, argv_copy[2]);
			exit(98);
		}

		write_count = write(target_file_desc, data_buffer, read_count);
		if (write_count == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv_copy[2]);
			free(data_buffer);
			close_file(source_file_desc, argv_copy[1]);
			close_file(target_file_desc, argv_copy[2]);
			exit(99);
		}

	} while (read_count > 0);

	free(data_buffer);
	close_file(source_file_desc, argv_copy[1]);
	close_file(target_file_desc, argv_copy[2]);

	return (0);
}

