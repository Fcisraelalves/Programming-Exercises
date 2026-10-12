#include <stdio.h>
#include <stdlib.h>

#define N 4

void statistics(const double *v, size_t n, double *mean, double *min, double *max) {
    double sum = *v;
    *min = *max = *v;
    for (int i = 1; i < n; i++) {
        if (*(v+i) < *min) {
            *min = *(v+i);
        }
        if (*(v+i) > *max) {
            *max = *(v+i);
        }
        sum += *(v+i);
    }

    *mean = sum / n;
}

int main() {

    double *v = malloc(N * sizeof(double));
    double min, max, mean;

    if (v == 0) {
        puts("insufficient memory!");
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        puts("Insert any number: ");
        scanf("%lf", (v+i));
    }



    statistics(v, N, &mean, &min, &max);

    printf("\nMean: %lf\n", mean);
    printf("\nMax: %lf\n", max);
    printf("\nMin: %lf\n", min);

    free(v);

    return 0;
}
