#include <stdio.h>
#include <stdlib.h>
void recursive_function(int depth) {
    int local [2048];  
    if (depth <= 0) {
        return;
    }  
    printf("Depth: %d\n", depth);
    recursive_function(depth - 1);
}

int main() {
    int  max_depth = 1000000;
    recursive_function(max_depth);
    printf("Рекурсія завершена!\n");  
    return 0;
}