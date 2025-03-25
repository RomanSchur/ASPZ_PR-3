#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/resource.h>

int num_choice[7];

void timeout_handler(int signum) {
    if (signum == SIGXCPU) {
        fprintf(stderr, "\nЧас вийшов!\n"); // Використовуємо stderr
        fflush(stderr); // Скидаємо буфер stderr
        exit(1);
    }
}

int check_unique(int number, int array[], int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == number) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int min, max, i, random_number;
    struct rlimit rl;
    time_t t;

    printf("Введіть початок діапазону вибору: ");
    scanf("%d", &min);
    printf("Введіть кінець діапазону вибору: ");
    scanf("%d", &max);

    rl.rlim_cur = 1;
    rl.rlim_max = 1;
    if (setrlimit(RLIMIT_CPU, &rl) == -1) {
        perror("Помилка встановлення ліміту часу ЦП");
        return 1;
    }

    signal(SIGXCPU, timeout_handler);
    srand((unsigned) time(&t));

    i = 0;
    while (i < 7) {
        random_number = (rand() % (max - min + 1)) + min;
        if (!check_unique(random_number, num_choice, i)) {
            num_choice[i] = random_number;
            i++;   
            //int j;         
            //for (j = 0; j < 100000000; j++) {
                 random_number = random_number * random_number % (max - min + 1);
           // }
          
        }
    }

    printf("\nРезультат:\n");
    for (i = 0; i < 7; i++) {
        printf("%d ", num_choice[i]);
    }
    printf("\n");
    return 0;
}
    