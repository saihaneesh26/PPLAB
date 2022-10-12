#include<stdio.h>
#include<stdlib.h>
#include<omp.h>


void main(){
	int n = 100;
	int a[100]; 
	int check=30;
	for(int i=0;i<n;i++)
		a[i] = i;
#pragma omp parallel
	for(int i=0;i<n;i++)
	{
		if(a[i]== check)
		{
			printf("FOUND in %d\n",i);

			break;
		}
	}
}
