#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<mpi.h>

void main(int c,char *v[]){
    int rank,size,root=0,dest=1,source=0,tag1=1,tag2=2;
    int out =77,in;
    MPI_Init(&c,&v);
    MPI_Status stat;
    MPI_Request req;
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    //no deadlock
    if(rank==0){
        dest = 1;
        source = 1;
        MPI_Send(&out,1,MPI_INT,dest,tag1,MPI_COMM_WORLD);
        MPI_Recv(&in,1,MPI_INT,source,tag2,MPI_COMM_WORLD,&stat);
    }
   else if(rank==1){  
        dest = 0;
        source = 0;
        MPI_Recv(&in,1,MPI_INT,source,tag1,MPI_COMM_WORLD,&stat);
        MPI_Send(&out,1,MPI_INT,dest,tag2,MPI_COMM_WORLD);  
   }
    printf("rank %d msg %d with tag %d from task %d\n",rank,in,stat.MPI_TAG,stat.MPI_SOURCE);
    MPI_Finalize();
}
/*
For deadlock condition
interchange the tags in else if part only
*/
