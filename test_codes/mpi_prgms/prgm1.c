#include<stdio.h>
#include<mpi.h>
#include<string.h>
#include<stdlib.h>
void main(int argc, char *argv[])
{
	char outmsg[100] = "welcome to ise!";
	char inmsg[100];
	int numtasks,rank,dest,source,rc,count,tag=1;
	MPI_Status stat;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	
	if(rank==0){
		dest = 1; //setting dest as rank 1
		//source=1;
		rc = MPI_Send(&outmsg,strlen(outmsg),MPI_CHAR,dest,tag,MPI_COMM_WORLD); 
	}
	else if(rank==1){
		//dest = 0;
		source=0; // mentioning source as rank 0
		rc = MPI_Recv(&inmsg,strlen(outmsg),MPI_CHAR,source,tag,MPI_COMM_WORLD,&stat);
	}
	rc = MPI_Get_count(&stat,MPI_CHAR,&count);
	printf("TASK %d, received %d char(s) task from %d with tag %d and msg is %s\n",rank,count,stat.MPI_SOURCE,stat.MPI_TAG,inmsg);
	MPI_Finalize();
}
