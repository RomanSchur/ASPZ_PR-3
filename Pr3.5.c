#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#define MAX_FILE_SIZE 3072

long get_size(const char *filename) {
    struct stat file_info;
    if (stat(filename, &file_info) == 0) {
        return file_info.st_size;  
    }
    return -1;  
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Програма потребує два аргументи\n");
        return 1;
    }    
    char *File_read = argv[1];  
    char *File_write = argv[2];

    FILE *srcFile, *emptFile;
    char buffer[1024]; 
    size_t bytesRead, bytesWritten;
   
    long fileSize = get_size(File_read);
    if (fileSize == -1) {
        printf("Не вдалося отримати розмір файлу %s\n", File_read);
        return 1;
    }

    if (fileSize > MAX_FILE_SIZE) {
        printf("Розмір файлу перевищує ліміт\n");
        return 1;
    }
    srcFile = fopen(File_read, "rb");
    if (srcFile == NULL) {
        printf("Не вдалося відкрити файл %s для читання\n", File_read);
        return 1;
    }   
    emptFile = fopen(File_write, "wb");
    if ( emptFile == NULL) {
        printf("Не вдалося відкрити файл %s для запису\n", File_write);
        fclose(srcFile);
        return 1;
    }
    
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
        bytesWritten = fwrite(buffer, 1, bytesRead,  emptFile);
        if (bytesWritten < bytesRead) {
            printf("Помилка при записі у файл %s\n", File_write);
            fclose(srcFile);
            fclose(emptFile);
            return 1;
        }
    }
    printf("Файл скопійовано\n");
    fclose(srcFile);
    fclose(emptFile);
    return 0;
}