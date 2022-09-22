#include<stdio.h>
#include <stdlib.h> 
void main()
{
	int n = 100000;
	int vector_a[100000],vector_b[100000], res_vector[100000];
	for(int i=0;i<n;i++)
	{
		vector_a[i] = rand()%100;
		vector_b[i] = rand()%10;	
	}
	vector_addn(n,res_vector,vector_a,vector_b);
}
