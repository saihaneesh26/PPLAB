#include<stdio.h>
#include<omp.h>
 


void vector_addn(int n,int* res_vector,int* vector_a,int* vector_b){
	#pragma omp parallel for	
	for(int i=0; i<n;i++)
	{
		res_vector[i] = vector_a[i]+vector_b[i];
	}
	printf("END of func\n");
}


//int main(){return 0;}
