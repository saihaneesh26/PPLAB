#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int j=1,primes[1000],x = 3;

int isPrime(int x){
//#pragma omp parallel for
	for(int i=2;i<x/2;i++)
	{
		if(x%i==0)
		{
			return 0;
		}
	}
	return 1;
}

void main(){
	#pragma omp parallel
	while(j<1000){
		if(isPrime(x))
		{	primes[j]=x;
			#pragma omp atomic
			j++;
		}	
		#pragma omp atomic
		x+=2;
	}	
	printf("%d",j);
}


