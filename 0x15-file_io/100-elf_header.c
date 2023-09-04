#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include "custom_elf_header.h"
#include <stdlib.h>

/**
 * main - Displays the information contained in the ELF header of an ELF file.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, other values on failure.
 */
int main(int argc, char *argv[])
{
	int elf_fd;
	unsigned char elf_ident[EI_NIDENT];
	ssize_t read_size;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (EXIT_FAILURE);
	}

	elf_fd = open(argv[1], O_RDONLY);
	if (elf_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	read_size = read(elf_fd, elf_ident, EI_NIDENT);

	if (read_size == -1)
	{
		close(elf_fd);
		dprintf(STDERR_FILENO, "Error: Unable to read file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	if (validateElfFile(elf_ident) == -1)
	{
		close(elf_fd);
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		return (EXIT_FAILURE);
	}

	printf("ELF Header:\n");
	displayElfMagicNumbers(elf_ident);
	displayElfClassInfo(elf_ident);
	displayElfDataInfo(elf_ident);
	displayElfVersionInfo(elf_ident);
	displayElfABIInfo(elf_ident);
	displayElfOSABIInfo(elf_ident);
	displayElfTypeInfo(elf_ident[16], elf_ident);
	displayElfEntryPoint(elf_ident[24], elf_ident);

	close(elf_fd);
	return (EXIT_SUCCESS);
}

