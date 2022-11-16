#include<stdio.h>
#include "mpi.h"

void main(int argc,char * argv[]){
	int rank,buf;
	const int root = 0;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	if(rank==root){
		buf=777;
	}
	printf("[%d]: before bcast, buf is %d\n",rank,buf);
	/*every one calls bcast,data is tanken from root and ends up in everyone's buf*/
	MPI_Bcast(&buf,1,MPI_INT,root,MPI_COMM_WORLD);
	printf("[%d]: after bcast, buf is %d\n",rank,buf);
	MPI_Finalize();
}
