/* --- Code 1 --- */

#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main(int argc , char **argv)
{
	double  *Array, *Array1, *Check, serial_sum, sum;
	int array_size, i,threadid,tval,Noofthreads;

             Noofthreads=16;
	printf("\nEnter the size of the array: ");
	scanf("%d", &array_size);
	printf("\t*****\n");

	Array = (double *) malloc(sizeof(double) * array_size);
	Check = (double *) malloc(sizeof(double) * array_size);

	for (i = 1; i <= array_size; i++) {
		Array[i] = i * 1;
		Check[i] = Array[i];
	}

	sum=0.0;
	omp_set_num_threads(Noofthreads);
 
	#pragma omp parallel for
	for (i = 1; i <= array_size; i++) 
          {
               printf("Thread number %d.\n",omp_get_thread_num());
		#pragma omp critical
		sum = sum + Array[i];
           }

	serial_sum = 0.0;
	for (i = 1; i <= array_size; i++)
		serial_sum = serial_sum + Check[i];

	if (serial_sum == sum)
		printf("\n\n\t\t The Serial And Parallel Sums Are Equal\n");
	else {
		printf("\n\\nt\t The Serial And Parallel Sums Are UnEqual\n");
		exit(1);
	}

	free(Check);
	free(Array);

	printf("\n\t\t The SumOfElements Of The Array Using OpenMP Directives Is %lf\n", sum);
	printf("\t\t The SumOfElements Of The Array By Serial Calculation Is %lf\n\n", serial_sum);
}
