#ifndef CUSTOM_ELF_HEADER_H
#define CUSTOM_ELF_HEADER_H

#include <elf.h>

int validateElfFile(unsigned char *e_ident);
void displayElfMagicNumbers(unsigned char *e_ident);
void displayElfClassInfo(unsigned char *e_ident);
void displayElfDataInfo(unsigned char *e_ident);
void displayElfVersionInfo(unsigned char *e_ident);
void displayElfABIInfo(unsigned char *e_ident);
void displayElfOSABIInfo(unsigned char *e_ident);
void displayElfTypeInfo(unsigned int e_type, unsigned char *e_ident);
void displayElfEntryPoint(unsigned long int e_entry, unsigned char *e_ident);

#endif /* CUSTOM_ELF_HEADER_H */

