#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5

double vector_mean(double *v, size_t n) {
    double sum = 0;

    for (int i = 0; i<n; i++) {
        sum += *(v+i);
    }

    return sum / n;
}

double vector_standard_deviation(double *v, size_t n) {
    double variance = 0;
    double mean = vector_mean(v, n);

    for (int i = 0; i<n; i++) {
        variance += (*(v+i) - mean) * (*(v+i) - mean);
    }
    variance /= n;

    return sqrt(variance);

}

int main() {
    double mean, std;
    double *v = malloc(N * sizeof(double));

    if (v == 0) {
        puts("Insufficient memory!");
        exit(1);
    }

    for (int i = 0; i<N; i++) {
        puts("Insert any number to fill the vector: ");
        scanf("%lf", (v+i));
    }

    mean = vector_mean(v, N);
    std = vector_standard_deviation(v, N);

    printf("Mean: %lf\n", mean);
    printf("Standard Deviation: %lf\n", std);

    free(v);

    return 0;
}
