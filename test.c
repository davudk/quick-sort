#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "qs.h"

bool is_sorted(int* src, size_t c) {
    for (size_t i = 1; i < c; i++) {
        if (src[i - 1] > src[i]) return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    const size_t COUNT = 1000 * 1000;
    int* src = malloc(COUNT * sizeof(int));

    srand(time(NULL));
    for (size_t i = 0; i < COUNT; i++) {
        src[i] = rand();
    }

    quicksort(src, COUNT);
    
    printf("The result %s sorted\n", is_sorted(src, COUNT) ? "is" : "is NOT");
    free(src);

    // pause
    getc(stdin);
}