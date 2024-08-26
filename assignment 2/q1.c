#include <stdio.h>
#include <omp.h>

void vector_scalar_addition(int *vector, int scalar, int *result, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        result[i] = vector[i] + scalar;
    }
}
int main() {
    int size = 100000;  
    int vector[size], result[size];
    int scalar = 5;
    
    for (int i = 0; i < size; i++) {
        vector[i] = i;
    }
   
    vector_scalar_addition(vector, scalar, result, size);
    printf("Result:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}