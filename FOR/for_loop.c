#include<omp.h>
#include<stdio.h>

void main(){
	int n = 10;
	#pragma omp parallel for
		for(int i=0;i<n;i++){
			printf("%d\n",i);		
		}
}
