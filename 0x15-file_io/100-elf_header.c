#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>

#define ELF_MAGIC_SIZE      4
#define ELF_CLASS_SIZE      1
#define ELF_DATA_SIZE       1
#define ELF_VERSION_SIZE    1
#define ELF_OSABI_SIZE      1
#define ELF_ABIVERSION_SIZE 1
#define ELF_TYPE_SIZE       2
#define ELF_ENTRY_SIZE      8

void read_bytes(int fd, void *buffer, size_t size, const char *error_msg)
{
	if (read(fd, buffer, size) != (ssize_t)size)
	{
		dprintf(2, "Error: Can't read %s\n", error_msg);
		close(fd);
		exit(98);
	}
}

void print_elf_magic(const char *elf_magic)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < ELF_MAGIC_SIZE; i++)
	{
		printf("%02x", (unsigned char)elf_magic[i]);
		if (i < ELF_MAGIC_SIZE - 1)
			printf(" ");
	}
}

void print_elf_class(const char *elf_class)
{
	printf("\n  Class:                             ELF%u", elf_class[0] == 1 ? 32 : 64);
}

void print_elf_data(const char *elf_data)
{
	printf("\n  Data:                              2's complement, %s endian", elf_data[0] == 1 ? "little" : "big");
}

void print_elf_version(const char *elf_version)
{
	printf("\n  Version:                           %u (current)", elf_version[0]);
}

void print_elf_osabi(const char *elf_osabi)
{
	printf("\n  OS/ABI:                            UNIX - ");
	switch (elf_osabi[0])
	{
	case 0:
		printf("System V");
		break;
	case 1:
		printf("HP-UX");
		break;
	case 2:
		printf("NetBSD");
		break;
	case 3:
		printf("Linux");
		break;
	case 6:
		printf("Solaris");
		break;
	default:
		printf("<unknown: %u>", elf_osabi[0]);
	}
}

void print_elf_abiversion(const char *elf_abiversion)
{
	printf("\n  ABI Version:                       %u", elf_abiversion[0]);
}

void print_elf_type(const char *elf_type)
{
	uint16_t type_value;
	printf("\n  Type:                              ");
	type_value = ((uint16_t)elf_type[1] << 8) | (uint16_t)elf_type[0];
	switch (type_value)
	{
	case 1:
		printf("REL (Relocatable file)");
		break;
	case 2:
		printf("EXEC (Executable file)");
		break;
	case 3:
		printf("DYN (Shared object file)");
		break;
	case 4:
		printf("CORE (Core file)");
		break;
	default:
		printf("<unknown: %04x>", type_value);
	}
}

void print_elf_entry(const char *elf_entry)
{
	int i;
	printf("\n  Entry point address:               0x");
	for (i = ELF_ENTRY_SIZE - 1; i >= 0; i--)
	{
		printf("%02x", (unsigned char)elf_entry[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int fd;
	char elf_magic[ELF_MAGIC_SIZE], elf_class[ELF_CLASS_SIZE];
	char elf_data[ELF_DATA_SIZE], elf_version[ELF_VERSION_SIZE];
	char elf_osabi[ELF_OSABI_SIZE], elf_abiversion[ELF_ABIVERSION_SIZE];
	char elf_type[ELF_TYPE_SIZE], elf_entry[ELF_ENTRY_SIZE];

	if (argc != 2)
	{
		dprintf(2, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}

	read_bytes(fd, elf_magic, ELF_MAGIC_SIZE, "ELF magic");

	read_bytes(fd, elf_class, ELF_CLASS_SIZE, "ELF class");

	read_bytes(fd, elf_data, ELF_DATA_SIZE, "ELF data encoding");

	read_bytes(fd, elf_version, ELF_VERSION_SIZE, "ELF version");

	read_bytes(fd, elf_osabi, ELF_OSABI_SIZE, "ELF OS/ABI");

	read_bytes(fd, elf_abiversion, ELF_ABIVERSION_SIZE, "ELF ABI version");

	read_bytes(fd, elf_type, ELF_TYPE_SIZE, "ELF type");

	read_bytes(fd, elf_entry, ELF_ENTRY_SIZE, "ELF entry point");

	printf("ELF Header:\n");
	print_elf_magic(elf_magic);
	print_elf_class(elf_class);
	print_elf_data(elf_data);
	print_elf_version(elf_version);
	print_elf_osabi(elf_osabi);
	print_elf_abiversion(elf_abiversion);
	print_elf_type(elf_type);
	print_elf_entry(elf_entry);

	close(fd);
	return (0);
}

