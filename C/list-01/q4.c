#include <stdio.h>
#include <stdlib.h>

#define N 4

void print_vector(double *v, size_t n) {
    for (int i = 0; i<n; i++) {
        printf("%lf ", *(v+i));
    }
    puts("");
}

void reverse(double *v, size_t n) {
    double *end_p = v + (n - 1);
    double aux;

    for (int i = 0; i < ((int) n / 2); i++) {
        aux = *(v + i);
        *(v+i) = *(end_p - i);
        *(end_p - i) = aux;
    }

}

int main() {

    double *v = malloc(N * sizeof(double));

    if (v == 0) {
        puts("insufficient memory!");
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        puts("Insert any number: ");
        scanf("%lf", (v+i));
    }

    puts("Initial vector:");
    print_vector(v, N);
    reverse(v, N);
    puts("Reverse vector:");
    print_vector(v, N);

    free(v);

    return 0;

}
