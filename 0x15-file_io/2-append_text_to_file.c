#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: The name of the file.
 * @text_content: A NULL-terminated string to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, result;
	ssize_t bytes_written = 0;

	if (filename == NULL)
		return (-1);

	/* Open the file for writing (append mode) */
	fd = open(filename, O_WRONLY | O_APPEND);
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

