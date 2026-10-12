#include <stdio.h>
#include <stdlib.h>

#define N 4

double dot_product(double *v1, double *v2, size_t n) {
    double result = 0;

    for (int i = 0; i < n; i++) {
        result += (*(v1 + i)) * (*(v2 + i));
    }

    return result;
}

int main() {

    double *v1 = malloc(N * sizeof(double));
    double *v2 = malloc(N * sizeof(double));
    double result;

    if (v1 == 0 || v2 == 0) {
        puts("Insufficient memory!");
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        puts("Insert any number to fill first vector: ");
        scanf("%lf", (v1 + i));
    }

    for (int i = 0; i < N; i++) {
        puts("Insert any number to fill second vector: ");
        scanf("%lf", (v2 + i));
    }

    result = dot_product(v1, v2, N);

    printf("Dot product: %lf\n", result);

    free(v1);
    free(v2);
    return 0;
}
