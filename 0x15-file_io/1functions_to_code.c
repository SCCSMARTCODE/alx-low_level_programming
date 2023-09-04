#include "custom_elf_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * displayElfOSABIInfo - Prints the OS/ABI of an ELF header.
 * @elf_ident: A pointer to an array containing the ELF version.
 */
void displayElfOSABIInfo(unsigned char *elf_ident)
{
printf(" OS/ABI: ");

switch (elf_ident[EI_OSABI])
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
printf("<unknown: %x>\n", elf_ident[EI_OSABI]);
	}
}

/**
 * displayElfABIInfo - Prints the ABI version of an ELF header.
 * @elf_ident: A pointer to an array containing the ELF ABI version.
 */
void displayElfABIInfo(unsigned char *elf_ident)
{
printf(" ABI Version: %d\n", elf_ident[EI_ABIVERSION]);
}

/**
 * displayElfTypeInfo - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @elf_ident: A pointer to an array containing the ELF class.
 */
void displayElfTypeInfo(unsigned int e_type, unsigned char *elf_ident)
{
if (elf_ident[EI_DATA] == ELFDATA2MSB)
e_type >>= 8;

printf(" Type: ");
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
 * displayElfEntryPoint - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @elf_ident: A pointer to an array containing the ELF class.
 */
void displayElfEntryPoint(unsigned long int e_entry, unsigned char *elf_ident)
{
printf(" Entry point address: ");

if (elf_ident[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) |
((e_entry >> 8) & 0xFF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}
if (elf_ident[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)e_entry);
else
printf("%#lx\n", e_entry);
}

/**
 * closeElfFile - Closes an ELF file.
 * @file: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void closeElfFile(int file)
{
if (close(file) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file);
exit(98);
}
}

