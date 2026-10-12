#include <stdio.h>
#include <stdlib.h>

#define N 3
double horner_method(double *v, size_t degree, double x) {
    double result = 0;
    for (int i = 0; i < degree; i++) {
        result *= x;
        result += *(v+i);
    }

    return result;
}

int main() {

    double result;
    double x;
    double *poly = malloc(N * sizeof(double));

    if (poly == 0) {
        puts("Insufficient memory!");
        exit(1);
    }

    for (int i = 0; i<N; i++) {
        printf("Insert any number to fill coefficients of the polynomial: ");
        scanf("%lf", (poly+i));
    }

    puts("Insert a value for the independent variable: ");
    scanf("%lf", &x);

    result = horner_method(poly, N, x);
    printf("Result: %lf\n", result);

    free(poly);

    return 0;
}
