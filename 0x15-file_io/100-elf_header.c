#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <stddef.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);


void print_elf_info(Elf64_Ehdr *header) {
    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x", header->e_ident[i]);
        if (i < EI_NIDENT - 1) {
            printf(" ");
        }
    }
    printf("\n");

    printf("Class:                             ");
    switch (header->e_ident[EI_CLASS]) {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown>\n");
            break;
    }

    printf("Data:                              ");
    switch (header->e_ident[EI_DATA]) {
        case ELFDATA2LSB:
            printf("2's complement, little-endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big-endian\n");
            break;
        default:
            printf("<unknown>\n");
            break;
    }

    printf("Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    
    printf("OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("Sun Solaris\n");
            break;
        case ELFOSABI_AIX:
            printf("IBM AIX\n");
            break;
        case ELFOSABI_IRIX:
            printf("SGI Irix\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("Compaq TRU64 UNIX\n");
            break;
        case ELFOSABI_MODESTO:
            printf("Novell Modesto\n");
            break;
        case ELFOSABI_OPENBSD:
            printf("OpenBSD\n");
            break;
        case ELFOSABI_ARM_AEABI:
            printf("ARM EABI\n");
            break;
        default:
            printf("<unknown>\n");
            break;
    }
    
    printf("ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    
    printf("Type:                              ");
    switch (header->e_type) {
        case ET_NONE:
            printf("NONE (No file type)\n");
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
            printf("<unknown>\n");
            break;
    }
    
    printf("Entry point address:               %#lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error");
        return 98;
    }

    Elf64_Ehdr header;
    ssize_t bytes_read = read(fd, &header, sizeof(Elf64_Ehdr));

    if (bytes_read != sizeof(Elf64_Ehdr) ||
        header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "Error: Not an ELF file\n");
        close(fd);
        return 98;
    }

    print_elf_info(&header);

    close(fd);
    return 0;
}

