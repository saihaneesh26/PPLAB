#include<stdio.h>
#include<omp.h>

void main(){
	int i,x=44;
	#pragma omp parallel for private(x)
	for(i = 0;i<10;i++)
	{
		x=i;
		printf("Thread :%d - %d\n",omp_get_thread_num(),x);
	}
	printf("\nLast x: %d\n",x);
}
