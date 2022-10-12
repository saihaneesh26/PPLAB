#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
void merge(int a[],int i1,int j1,int i2,int j2)
{
	int temp[1000];
	int i,j,k;
	i = i1;j=i2;k=0;
	while(i<=j1 && j<j2)
	{
		if(a[i]<a[j])
			temp[k++] = a[i++];
		else temp[k++] = a[j++];
	}
	while(i<=j1) temp[k++]=a[i++];
	while(j<=j2) temp[k++]=a[j++];

	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=temp[j];
}


void mergesort(int a[],int i,int j)
{
int mid;
if(i<j)
{
	mid = (i+j)/2;
	#pragma omp parallel sections
	{
		#pragma omp section
		mergesort(a,i,mid);
		#pragma omp section
		mergesort(a,mid+1,j);
	}
	merge(a,i,mid,mid+1,j);
}
}

void main()
{
	int *a,num,i;
	scanf("enter num:%d",&num);
	a = (int *)malloc(sizeof(int)*num);
	for(i=0;i<num;i++) a[i]= rand()%100;
	double start = omp_get_wtime();
	mergesort(a,0,num-1);
	double end = omp_get_wtime();
	double val = end - start;
	printf("Time is:%f\n",val);
}


