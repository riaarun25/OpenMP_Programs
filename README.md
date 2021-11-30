# OpenMP Programs

### -> matrixmul.c
Write a C program to perform parallel matrix multiplication using OpenMP. You should first create three matrices A, B, and C then initialize A and B to some values of your choice. In your code, try to improve the performance by (re)using the same set of threads for initializing A and B and for calculating C.

### -> messagepassing.c
Write a C program to handle message passing in the MPI application interface, which allows processes to communicate with one another. Create two processes that will pass the number 17 from one to the other.

### -> scatterandgather.c
Write a C program to handle message passing in the MPI application interface using Group Operators: Scatter and Gather.

### -> sum_of_elements.c
Write an OpenMP code to find the Sum of Elements of a One-Dimensional Real Array using vector addition. Where the two vectors A and B are added into C by spawning a team of threads and assigning a chunk of work to each thread.  
Note: Sets the environment variable omp_num_threads to 6.

### -> sum_of_numbers.c
Create an OpenMP program that uses the Work Sharing Directive to add all the numbers between 1 and 100. Work-sharing directives simplify and effectively split normally serial tasks into fast parallel sections of code. To declare the loop as work sharing, use the #pragma omp.
