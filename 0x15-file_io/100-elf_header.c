#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_elf_header - Print the ELF header information.
 * @header: Pointer to the ELF header structure.
 */
void print_elf_header(Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf("\tMagic:\t");
	for (i = 0; i < EI_NIDENT; i++)
	{	printf("%02x ", header->e_ident[i]);	}
	printf("\n");
	printf("\tClass:\t\t\t\t%s\n",
		(header->e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "ELF32");
	printf("\tData:\t\t\t\t%s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ?
		"2's complement, little endian" : "unknown");
	printf("\tVersion:\t\t\t%d (current)\n", header->e_ident[EI_VERSION]);
	printf("\tOS/ABI:\t\t\t");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		default:
			printf("<unknown: %02x>\n", header->e_ident[EI_OSABI]);
	}
	printf("\tABI Version:\t\t\t%d\n", header->e_ident[EI_ABIVERSION]);
	printf("\tType:\t\t\t\t");
	switch (header->e_type)
	{
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		default:
			printf("<unknown: %04x>\n", header->e_type);
	}	printf("\tEntry point address:\t\t0x%lx\n", header->e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	int fd;

	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (98);
	}
	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		perror("read");
		close(fd);
		return (98);
	}
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
		header.e_ident[EI_MAG1] != ELFMAG1 ||
		header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Not an ELF file.\n");
		close(fd);
		return (98);
	}
	print_elf_header(&header);
	close(fd);
	return (0);
}

