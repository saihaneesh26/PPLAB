#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
//compile using : gcc -fopenmp prgm6.c vect_addn_func.c
//to run ./a.out in ubuntu and a in windows

void vector_addn_parallel(int n,int *res_vector,int *vector_a, int *vector_b){
    #pragma omp parallel for	
	for(int i=0; i<n;i++)
	{
		res_vector[i] = vector_a[i]+vector_b[i];
	}
}

void main(){
    int n = 100000;
	int vector_a[100000],vector_b[100000], res_vector[100000];
	for(int i=0;i<n;i++)
	{
		vector_a[i] = rand()%10;
		vector_b[i] = rand()%10;	
	}
    double start = omp_get_wtime();
	vector_addn_parallel(n,res_vector,vector_a,vector_b);
    double end = omp_get_wtime();
    printf("Parallel Time %f\n",end-start);
}
