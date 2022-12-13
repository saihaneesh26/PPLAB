#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
//do not give high input bcos the stack will overflow and no output will be seen (segmentation fault)
//try n = 7 or 8
void main(int argc,char * argv[]){
	int n,rank,size;
	scanf("%d",&n);
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	int root=0;
	
	int global;	
		//len = (n/size)+1;
		//printf("len %d\n",len);
	
	MPI_Bcast(&n,1,MPI_INT,root,MPI_COMM_WORLD);
	int localprod=1;
	int len = (n/size)+1;
	//printf("RANK %d\n",rank);
	for(int i=1;i<=len;i++){
		printf("rank %d len:%d i:%d\n n:%d",rank,len,i,n);
		int val = (rank*len) + i;
		printf("rank: %d val :%d\n",rank,val);
		if(val<=n)
		localprod *= val;
		else break;
	}
	/*
	//above for loop can be minimized
	for(int i=(rank*len)+1;i<=((rank+1)*len);i++){
        	if(i>n) break;
        	locaprodl*=i;
    	}
	*/
	printf("LOCAL PROF:%d\n",localprod);
MPI_Reduce(&localprod,&global,1,MPI_INT,MPI_PROD,root,MPI_COMM_WORLD);
if(rank==root)
		printf("Factorial of %d is %d\n",n,global);
	MPI_Finalize();

	
}
