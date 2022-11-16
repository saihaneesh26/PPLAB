#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>

void main(int argc,char* argv[]){

	int rank,nprocs;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&nprocs);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Barrier(MPI_COMM_WORLD);
	printf("msg from %d\n",rank);
	fflush(stdout);
	MPI_Finalize();
}
