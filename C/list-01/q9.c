#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double euclidian_distance(const double *v1, const double *v2, size_t n) {
    double distance = 0;
    for (int i = 0; i<n; i++) {
        distance += (*(v1+i) - *(v2+i)) * (*(v1+i) - *(v2+i));
    }

    return sqrt(distance);
}
int main() {

    unsigned short int n;
    double distance;


    puts("Insert a value to n: ");
    scanf("%hu", &n);

    double *v1 = malloc(n * sizeof(double));
    double *v2 = malloc(n * sizeof(double));

    if (v1 == 0 || v2 == 0) {
        puts("Insufficient memory!");
        exit(1);
    }

    for (int i = 0; i<n; i++) {
        puts("Insert a coordinate to first vector: ");
        scanf("%lf", (v1+i));
        puts("Insert a coordinate to second vector: ");
        scanf("%lf", (v2+i));
    }

    distance = euclidian_distance(v1, v2, n);

    printf("Euclidian Distance: %lf\n", distance);

    free(v1);
    free(v2);

    return 0;
}
