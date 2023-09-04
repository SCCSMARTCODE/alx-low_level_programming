/* custom_elf_combined.c */

#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void check_custom_elf(unsigned char *e_ident);
void print_custom_magic(unsigned char *e_ident);
void print_custom_class(unsigned char *e_ident);
void print_custom_data(unsigned char *e_ident);
void print_custom_version(unsigned char *e_ident);
void print_custom_abi(unsigned char *e_ident);
void print_custom_osabi(unsigned char *e_ident);
void print_custom_type(unsigned int e_type, unsigned char *e_ident);
void print_custom_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_custom_elf(int elf);

/**
 * check_custom_elf - Checks if a file is a custom ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not a custom ELF file - exit code 98.
 */
void check_custom_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
		    e_ident[index] != 'C' &&
		    e_ident[index] != 'U' &&
		    e_ident[index] != 'S' &&
		    e_ident[index] != 'T' &&
		    e_ident[index] != 'M' &&
		    e_ident[index] != 'E' &&
		    e_ident[index] != 'L' &&
		    e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not a custom ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_custom_magic - Prints the magic numbers of a custom ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_custom_magic(unsigned char *e_ident)
{
	int index;

	printf(" Custom Magic: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_custom_class - Prints the class of a custom ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_custom_class(unsigned char *e_ident)
{
	printf(" Custom Class: ");

	switch (e_ident[EI_CLASS])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_custom_data - Prints the data of a custom ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_custom_data(unsigned char *e_ident)
{
	printf(" Custom Data: ");

	switch (e_ident[EI_DATA])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_custom_version - Prints the version of a custom ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_custom_version(unsigned char *e_ident)
{
	printf(" Custom Version: %d",
		   e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_custom_osabi - Prints the OS/ABI of a custom ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_custom_osabi(unsigned char *e_ident)
{
	printf(" Custom OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_custom_abi - Prints the ABI version of a custom ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void print_custom_abi(unsigned char *e_ident)
{
	printf(" Custom ABI Version: %d\n",
		   e_ident[EI_ABIVERSION]);
}

/**
 * print_custom_type - Prints the type of a custom ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_custom_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Custom Type: ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_custom_entry - Prints the entry point of a custom ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_custom_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Custom Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
				  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_custom_elf - Closes a custom ELF file.
 * @elf: The file descriptor of the custom ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_custom_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * custom_elf_main - Displays the information contained in the
 * custom ELF header at the start of a custom ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not a custom ELF File or
 * the function fails - exit code 98.
 */
int custom_elf_main(int argc, char *argv[])
{
	Elf64_Ehdr *header;
	int file_descriptor, read_result;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_custom_elf(file_descriptor);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	read_result = read(file_descriptor, header, sizeof(Elf64_Ehdr));
	if (read_result == -1)
	{
		free(header);
		close_custom_elf(file_descriptor);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_custom_elf(header->e_ident);
	printf("Custom ELF Header:\n");
	print_custom_magic(header->e_ident);
	print_custom_class(header->e_ident);
	print_custom_data(header->e_ident);
	print_custom_version(header->e_ident);
	print_custom_osabi(header->e_ident);
	print_custom_abi(header->e_ident);
	print_custom_type(header->e_type, header->e_ident);
	print_custom_entry(header->e_entry, header->e_ident);

	free(header);
	close_custom_elf(file_descriptor);
	return (0);
}

int main(int argc, char *argv[])
{
	return custom_elf_main(argc, argv);
}

