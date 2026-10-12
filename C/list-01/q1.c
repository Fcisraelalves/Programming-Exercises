#include <stdio.h>
#include <stdlib.h>

#define N 3

int vector_sum(int *v, size_t n) {
    int sum = 0;

    for (int i = 0; i<n; i++) {
        sum +=  *(v+i);
    }

    return sum;
}


int main() {
    int sum;
    int *v = malloc(N * sizeof(int));

    if (v == 0) {
        puts("Insufficient memory!");
        exit(1);
    }

    for (int i = 0; i<N; i++) {
        puts("Insert any number to fill the vector: ");
        scanf("%i", (v+i));
    }

    sum = vector_sum(v, N);

    printf("Sum of the vector elements: %i\n", sum);

    free(v);
    return 0;
}
