/*Array Size = 4*/
#include <stdio.h>
#include <mpi.h>
int main(int argc, char** argv){
  int process_Rank, size_of_Comm;
  int distro_Array[4] = {25, 134, 93, 61};
  int scattered_Data;
  
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size_of_Comm);
  MPI_Comm_rank(MPI_COMM_WORLD, &process_Rank);
  
  MPI_Scatter(&distro_Array, 1, MPI_INT, &scattered_Data, 1, MPI_INT, 0, MPI_COMM_WORLD);
  printf("MPI Scatter Output -> ");
  printf("Process received: %d \n", scattered_Data);
  MPI_Gather (&scattered_Data, 1, MPI_INT, &distro_Array, 1, MPI_INT, 0, MPI_COMM_WORLD); 
  printf("MPI Gather Output -> ");
  printf("Process received: %d \n", *distro_Array);
  MPI_Finalize();
  return 0;
}

/*Array Size = 3*/
#include <stdio.h>
#include <mpi.h>
int main(int argc, char** argv){
  int process_Rank, size_of_Comm;
  int distro_Array[3] = {25, 134, 61};
  int scattered_Data;
  
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size_of_Comm);
  MPI_Comm_rank(MPI_COMM_WORLD, &process_Rank);
  
  MPI_Scatter(&distro_Array, 1, MPI_INT, &scattered_Data, 1, MPI_INT, 0, MPI_COMM_WORLD);
  printf("MPI Scatter Output -> ");
  printf("Process received: %d \n", scattered_Data);
  MPI_Gather (&scattered_Data, 1, MPI_INT, &distro_Array, 1, MPI_INT, 0, MPI_COMM_WORLD); 
  printf("MPI Gather Output -> ");
  printf("Process received: %d \n", *distro_Array);
  MPI_Finalize();
  return 0;
}
