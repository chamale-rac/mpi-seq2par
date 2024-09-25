/*
mpi_hello_2.c
Author: Samuel Chamalé
Date: September 24, 2024
Description: MPI program where all processes send a message to process 0,
and process 0 receives and displays all the messages.
Compilation: mpicc -o mpi_hello_2 mpi_hello_2.c
Usage: mpirun -np 4 ./mpi_hello_2
*/

#include <mpi.h>  // Include the MPI library
#include <stdio.h>  // Include standard I/O library
#include <stdlib.h> // Include for exit()

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Variables to store the number of processes and the current process ID
    int world_size, world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Buffer for receiving messages
    char message[100];

    if (world_rank == 0) {
        // Process 0: Receiving messages from all other processes
        printf("Hi, I'm process %d of %d and I'm receiving!\n", world_rank, world_size);
        for (int i = 1; i < world_size; i++) {
            MPI_Recv(message, 100, MPI_CHAR, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Greetings process 0, I'm process %s!\n", message);
        }
    } else {
        // Other processes: Sending a message to process 0
        sprintf(message, "%d of %d", world_rank, world_size);
        printf("Hi, I'm process %d of %d and I'm sending a message to 0!\n", world_rank, world_size);
        MPI_Send(message, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }

    // Finalize the MPI environment
    MPI_Finalize();

    return 0;
}
