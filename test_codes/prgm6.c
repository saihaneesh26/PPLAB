#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
//compile using : gcc -fopenmp prgm6.c vect_addn_func.c
//to run ./a.out in ubuntu and a in windows
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