#include <stdio.h>
#include <stdlib.h>

#define N 11

void find_max_min_values(double *v, size_t n, double *min, double *max) {
    *min = *max = *v;
    for (int i = 1; i<n; i++) {
        if (*(v+i) < *min) {
            *min = *(v+i);
        }
        if (*(v+i) > *max) {
            *max = *(v+i);
        }
    }
}

void min_max_scaler(double *v, size_t n) {
    double min, max;
    find_max_min_values(v, n, &min, &max);

    for (int i = 0; i<n; i++) {
        if (min == max) {
            *(v+i) = 0;
        } else {
            *(v+i) = (*(v+i) - min) / (max - min);
        }
    }
}

void print_vector(double *v, size_t n) {
    for (int i = 0; i<n; i++) {
        printf("%lf ", *(v+i));
    }
    puts("");
}

int main() {

    double *v = malloc(N * sizeof(double));

    if (v == 0) {
        puts("Insufficient memory!");
        exit(1);
    }

    for (int i = 0; i<N; i++) {
        puts("Insert any number to fill the vector: ");
        scanf("%lf", (v+i));
    }

    puts("\nInitial vector: ");
    print_vector(v, N);

    min_max_scaler(v, N);
    puts("\nNormalized vector: ");
    print_vector(v, N);

    free(v);
    return 0;

}
