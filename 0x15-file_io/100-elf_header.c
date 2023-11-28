#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct {
    unsigned char e_ident[16];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint32_t e_entry;
    uint32_t e_phoff;
    uint32_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf32_Ehdr;

void display_elf_header(const Elf32_Ehdr *header);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    const char *elf_filename = argv[1];

    int elf_file = open(elf_filename, O_RDONLY);
    if (elf_file == -1) {
        perror("Error opening file");
        exit(98);
    }

    Elf32_Ehdr elf_header;
    if (read(elf_file, &elf_header, sizeof(Elf32_Ehdr)) != sizeof(Elf32_Ehdr)) {
        perror("Error reading ELF header");
        close(elf_file);
        exit(98);
    }

    if (elf_header.e_ident[1] != 'E' || elf_header.e_ident[2] != 'L' || elf_header.e_ident[3] != 'F') {
        fprintf(stderr, "Error: Not an ELF file\n");
        close(elf_file);
        exit(98);
    }

    display_elf_header(&elf_header);

    close(elf_file);

    return 0;
}

/**
 * display_elf_header - Displays information about the ELF header.
 * @header: Pointer to the ELF header structure.
 */
void display_elf_header(const Elf32_Ehdr *header) {
    printf("Magic:   ");
    for (int i = 0; i < 16; ++i)
        printf("%02x ", header->e_ident[i]);
    printf("\n");

    printf("Class:                             ELF%d\n", header->e_ident[4] == 1 ? 32 : 64);
    printf("Data:                              %s\n", header->e_ident[5] == 1 ? "2's complement, little endian" : "2's complement, big endian");
    printf("Version:                           %d (current)\n", header->e_version);
    printf("OS/ABI:                            UNIX - System V\n");
    printf("ABI Version:                       0\n");
    printf("Type:                              %s\n", header->e_type == 2 ? "EXEC (Executable file)" : "Not specified");
    printf("Entry point address:               0x%x\n", header->e_entry);

    printf("\n");
}
