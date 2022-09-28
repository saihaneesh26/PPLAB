#include<stdio.h>
#include<omp.h>
void main(void)
{
	int n=4;
	#pragma omp parallel for collapse(2) num_threads(8) 
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<n;j++){		

			printf("Thread: %d: (%d, %d)\n",omp_get_thread_num(),i,j); 			
		}
	}
}
