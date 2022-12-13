#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

void main(int argc,char* v[]){
	int rank,size,root=0;
	int n=10;

	int a[100],b[100],c[100];
	printf("array A\n");
	for(int i=0;i<n;i++){
		a[i] = rand()%10;
		printf("%d ",a[i]);
	}
	printf("\n array B\n");
	for(int i=0;i<n;i++)
	{
		b[i] = rand()%10;
		printf("%d ",b[i]);
	}printf("\n");

	MPI_Init(&argc,&v);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	int subsize = n/size;
	int *ap = malloc(sizeof(int)*subsize);
	int *bp = malloc(sizeof(int)*subsize);
	int *cp = malloc(sizeof(int)*subsize);

	MPI_Scatter(a,subsize,MPI_INT,ap,subsize,MPI_INT,root,MPI_COMM_WORLD);
	MPI_Scatter(b,subsize,MPI_INT,bp,subsize,MPI_INT,root,MPI_COMM_WORLD);

	for(int i=0;i<subsize;i++){
		cp[i] = ap[i]+bp[i];
	}

	MPI_Gather(cp,subsize,MPI_INT,c,subsize,MPI_INT,root,MPI_COMM_WORLD);
	if(rank==root){
		printf("res:\n");
		for(int i=0;i<n;i++){
			printf("%d ",c[i]);
		}
		printf("\n");
	}
	MPI_Finalize();
}
