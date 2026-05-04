#include <stdio.h>
#include <string.h>

int openfile() {
    FILE *file;
    char buffer[100];
    char* search = ""; // TARGET HERE

    file = fopen("sample.txt", "r");
    // CHECK IF EXISTS
    if (file == NULL) {
        printf("Arquivo de texto não encontrado\n");
        return 1;
    }
    else {
        printf("Arquivo aberto\n");

        // READS
        while (fgets(buffer, 100, file)) {
            char* found = strstr(buffer, search);
            if (found) {
                printf("Palavra encontrada\n");
            }
            else {
                printf("Palavra não encontrada\n");
            }
        }
        return 0;
    }

    // FREE
    fclose(file);
}

int main(void) {
    openfile();
}