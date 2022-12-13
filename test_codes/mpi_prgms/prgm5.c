#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int isprime(int x){
	if(x==0) return 0;
	if(x==1) return 0;
	if(x==2)return 1;
	if(x==3)return 1;
	for(int i=2;i<=x/2;i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}

void main(int argc,char *argv[])
{
	int size,rank,root=0;
 int n ;
        printf("enter n\n");
        scanf("%d",&n);
int *globaldata = malloc(n*sizeof(int));
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Bcast(&n,1,MPI_INT,root,MPI_COMM_WORLD);
	for(int i=0;i<n;i++)
	{
		globaldata[i] = i+1;
	}
	int itern = (n/size)+1;
	printf("\nrank %d itern %d size %d n %d\n",rank,itern,size,n);
	for(int i=(rank*itern);i<((rank+1)*itern);i++)
	{
		if(i>n) break;

		if(isprime(globaldata[i])){
			printf("%d ",globaldata[i]);
		}
	}
	MPI_Finalize();
}
