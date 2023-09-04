#include "custom_elf_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * validateElfFile - Checks if a file is an ELF file.
 * @elf_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
int validateElfFile(unsigned char *elf_ident)
{
	int in;

	for (in = 0; in < 4; in++)
	{
		if (elf_ident[in] != 127 &&
		    elf_ident[in] != 'E' &&
		    elf_ident[in] != 'L' &&
		    elf_ident[in] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}

	return (0);
}

/**
 * displayElfMagicNumbers - Prints the magic numbers of an ELF header.
 * @elf_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void displayElfMagicNumbers(unsigned char *elf_ident)
{
	int ex;

	printf(" Magic: ");

	for (ex = 0; ex < EI_NIDENT; ex++)
	{
		printf("%02x", elf_ident[ex]);

		if (ex == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * displayElfClassInfo - Prints the class of an ELF header.
 * @elf_ident: A pointer to an array containing the ELF class.
 */
void displayElfClassInfo(unsigned char *elf_ident)
{
	printf(" Class: ");

	switch (elf_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_ident[EI_CLASS]);
	}
}

/**
 * displayElfDataInfo - Prints the data of an ELF header.
 * @elf_ident: A pointer to an array containing the ELF class.
 */
void displayElfDataInfo(unsigned char *elf_ident)
{
	printf(" Data: ");

	switch (elf_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_ident[EI_CLASS]);
	}
}

/**
 * displayElfVersionInfo - Prints the version of an ELF header.
 * @elf_ident: A pointer to an array containing the ELF version.
 */
void displayElfVersionInfo(unsigned char *elf_ident)
{
	printf(" Version: %d", elf_ident[EI_VERSION]);

	switch (elf_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}
