#include<stdio.h>
#include<omp.h>
 
void vector_addn_parallel(int n,int *res_vector,int *vector_a, int *vector_b){
    #pragma omp parallel for	
	for(int i=0; i<n;i++)
	{
		res_vector[i] = vector_a[i]+vector_b[i];
	}
}
