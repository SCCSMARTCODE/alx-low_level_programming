#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * create_file - Creates a file with the given filename and
 * @filename: The name of the file to create.
 * @text_content: A NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, result;
	ssize_t bytes_written = 0;

	if (filename == NULL)
		return (-1);

	/* Open the file (create if it doesn't exist) with read/write permissions */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	/* Write text_content to the file if it is not NULL */
	if (text_content != NULL)
	{
		while (text_content[bytes_written] != '\0')
			bytes_written++;
		result = write(fd, text_content, bytes_written);
		if (result == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

