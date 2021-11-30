#include<stdio.h>

int main(){
    #define NRA 3
    #define NCA 3
    #define NCB 3
    
    int c, d, k, sum = 0;
    int first[10][10], second[10][10], multiply[10][10];
    
    printf("Enter elements of first matrix: \n");
    for (c = 0; c < NRA; c++)
    for (d = 0; d < NCA; d++)
    scanf("%d", &first[c][d]);
    
    printf("Enter elements of second matrix: \n");
    for (c = 0; c < NCA; c++) 
    for (d = 0; d < NCB; d++) 
    scanf("%d", &second[c][d]);
    
    #pragma omp parallel for default(none) shared(first,second,multiply)
    for (c = 0; c < NRA; c++) {
        for (d = 0; d < NCB; d++) {
            for (k = 0; k < NCA; k++) {
                sum = sum + first[c][k]*second[k][d];
                }
                multiply[c][d] = sum;
                sum = 0;
                }
                }
                
                printf("Product of the matrices:\n");
                for (c = 0; c < NRA; c++) {
                    for (d = 0; d < NCB; d++)
                    printf("%d\t", multiply[c][d]);
                    printf("\n");
                    } 
                    return 0;
                    }
