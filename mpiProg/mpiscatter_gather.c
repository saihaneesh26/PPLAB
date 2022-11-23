#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

void main(int argc,char *argv[])
{
	int size,rank,root=0;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	int globaldata[16],localdata[4],localdatas[16];
	if(rank==root)
	{
		for(int i=0;i<16;i++) globaldata[i]=i;	
	}
	//int buffer[4];
	MPI_Scatter(globaldata,2,MPI_INT,localdata,4,MPI_INT,root,MPI_COMM_WORLD);
	
	MPI_Gather(&localdata,4,MPI_INT,localdatas,4,MPI_INT,root,MPI_COMM_WORLD);

	printf("task: %d - LOCALDATA:\n",rank);
	for (int i=0;i<4;i++)printf("%d ",localdata[i]);
	printf("\n");

	MPI_Finalize();
}
