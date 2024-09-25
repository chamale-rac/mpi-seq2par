/*
mpi_hello.c
Author: Samuel Chamalé
Date: September 24, 2024
Description: MPI program that prints "Hello World" from multiple processes.
Each process shows its ID and the total number of available processes.
Compilation: mpicc -o mpi_hello mpi_hello.c
Usage: mpirun -np 4 ./mpi_hello
*/

#include <mpi.h>  // Include the MPI library
#include <stdio.h>  // Include the standard I/O library
#include <stdlib.h> // Include for the use of exit()

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Variables to store the number of processes and the current process ID
    int world_size, world_rank;

    // Get the total number of processes
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the ID of the current process
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Print message from each process
    printf("Hello World, I’m process %d of %d!\n", world_rank, world_size);

    // Finalize the MPI environment
    MPI_Finalize();

    return 0;
}
