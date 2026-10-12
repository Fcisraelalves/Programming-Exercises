#include <stdio.h>
#include <stdlib.h>

void print_vector(int *v, size_t n) {
    for (int i = 0; i<=n; i++) {
        printf("%i ", *(v+i));
    }
    puts("");
}

int main() {

    unsigned short int n;


    puts("Insert a value to n: ");
    scanf("%hu", &n);

    int *v = malloc(n * sizeof(int));

    if (v == 0) {
        puts("Insufficient memory!");
        exit(1);
    }

    for (int i = 0; i<=n; i++) {
        *(v+i) = i * i;
    }

    printf("Square numbers from 0 to %i: \n", n);
    print_vector(v, n);
    free(v);
    return 0;
}
