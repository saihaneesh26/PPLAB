#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int ops = 0;

void vector_addn(int n,int *res,int * a,int *b)
{
	#pragma omp parallel for

	for(int i=0;i<n;i++)
	{
		res[i] = a[i]+b[i];
		#pragma omp critical
		{
			ops+=1;
		}
	}
			
	
	
}

void main(){
	int *a,*b,*res;
	int n = 1000;
	a = malloc(sizeof(int)*n);
	b = malloc(sizeof(int)*n);
	res = malloc(sizeof(int)*n);

	for (int i=0;i<n;i++)
	{
		a[i] = rand()%10;
		b[i] = rand()%10;
	}

	vector_addn(n,res,a,b);
	printf("%d\n",ops);
}
