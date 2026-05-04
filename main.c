#include <stdio.h>
#include <windows.h>
#include <errhandlingapi.h>

int openfile() {
    HANDLE file; // Pointer to VOID, used to initialize any kind of variable
    char *path_to_file = ""; // INSER THE PATH TO THE FILE HERE
    file = CreateFile(path_to_file, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    LARGE_INTEGER fileSize;
    GetFileSizeEx(file, &fileSize);

    char* filebuffer = malloc(fileSize.QuadPart + 1); /* x64 */
    char* search = ""; // TARGET WORD HERE

    /* If FILE NOT FOUND */
    if (file == INVALID_HANDLE_VALUE) {
        printf("Erro ao abrir o arquivo\nVerifique se o mesmo existe\n"); // Error to open file, verify if it exists
        return 1;
    }
    else {
        printf("Arquivo aberto com sucesso!\n"); // File opened with success
        DWORD bytes_read;
        if (ReadFile(file, filebuffer, (DWORD)fileSize.QuadPart, &bytes_read, NULL)){
            filebuffer[bytes_read] = '\0'; // EOF
            // NOTE: Case sensitive
            char* found = strstr(filebuffer, search);
            if (found) {
                printf("Palavra encontrada\n"); // Word found
            }
            else {
                printf("Palavra não encontrada\n"); // Word not found
            }
        }
    }

    // free memory
    free(filebuffer);
    CloseHandle(file);
    return 0;
}

int main(void) {
    openfile();
}