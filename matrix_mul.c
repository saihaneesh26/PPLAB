#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

void main(void)
{
	int n = 500;
	int matA[500][500],matB[500][500],matC[500][500];
	for(int i=0;i<n;i++)
	for(int j = 0;j<n;j++)
	//for(int k=0;k<n;k++)
	{
		matA[i][j] = rand()%10;
		matB[i][j] = rand()%10;
	}
	#pragma omp parallel for collapse(2)
	for(int i=0;i<n;i++)
	for(int j = 0;j<n;j++)
	{
		int val = 0;
		for(int k=0;k<n;k++)
		{
			val += matA[i][k]*matB[k][j];
		}
		matC[i][j] = val;
	}
/*
for(int i=0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			printf("%d ",matA[i][j]);	
		}
		printf("\n");
	}
printf("\n");
for(int i=0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			printf("%d ",matB[i]sa[j]);	
		}
		printf("\n");
	}printf("\n");

	for(int i=0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			printf("%d ",matC[i][j]);	
		}
		printf("\n");
	}
*/
}
