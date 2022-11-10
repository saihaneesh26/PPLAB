#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mpi.h>

void main(int argc, char *argv[]){

	int size,rc,count,rank,tag=1,dest,source;
	MPI_Init(&argc,&argv);
	char outmsg[100]="Welcome to ise!",inmsg[100];
	count = strlen(outmsg);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Request req;
	MPI_Status status;

	if(rank==0){
		dest = 1;
		source=1;
		MPI_Isend(&outmsg,count,MPI_CHAR,dest,tag,MPI_COMM_WORLD,&req);
		printf("sending msg from task %d\n",rank);
	}
	else if(rank==1){
		dest = 0;
		source = 0;
		rc=MPI_Recv(inmsg,count,MPI_CHAR,source,tag,MPI_COMM_WORLD,&status);
		printf("Receiving msg in task %d : %s\n ",rank,inmsg);
	}
	MPI_Finalize();

}
