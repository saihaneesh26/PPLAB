#include<stdio.h>
#include<omp.h>

void main()
{
	int n= 5;
	#pragma omp parallel for
	for(int i=1;i<n;i++)
		for(int j =1;j<n;j++)
			printf("%d : (%d , %d)\n",omp_get_thread_num(),i,j);
}
