#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#define MAX_FILE_SIZE 1024
#define FILE_NAME "Pr3.3.txt"

long get_size(const char *filename) {
    struct stat file_info;
    if (stat(filename, &file_info) == 0) {
        return file_info.st_size;
    }
    return -1;  
}

int main() {
    srand(time(NULL));
    int min = 1;
    int max = 6;
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Помилка відкриття файлу");
        return 1;
    }

    for (int i = 1; i <= 2; i++) {
        long file_size = get_size(FILE_NAME);
        if (file_size < 0) {
            printf("Помилка отримання розміру файлу\n");
            fclose(file);
            return 1;
        }

     int res = (rand() % (max - min + 1)) + min;
     char check[100];
      int new_size = snprintf(check, sizeof(check), "Результат кидка кубика №%d: %d\n", i, res);
     
      if (file_size + new_size > MAX_FILE_SIZE) {
          printf("Помилка: Файл досягне максимального розміру \n");
          break;
        }       
        fprintf(file, "%s", check);      
    }
    fclose(file);
    return 0;
}
