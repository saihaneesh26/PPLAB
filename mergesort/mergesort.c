// C program for Merge Sort
#include <stdio.h>
#include <stdlib.h>
#include<omp.h>
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l,
		int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays
	int L[n1], R[n2];

	// Copy data to temp arrays
	// L[] and R[]
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temp arrays back
	// into arr[l..r]
	// Initial index of first subarray
	i = 0;

	// Initial index of second subarray
	j = 0;

	// Initial index of merged subarray
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements
	// of L[], if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of
	// R[], if there are any
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted
void mergesortParallel(int a[],int l,int h){
    if(l<h){
        int mid = l+(h-l)/2;
        
        #pragma omp parallel sections
        {
            #pragma omp section
            mergesortParallel(a,l,mid);
            
            #pragma omp section
            mergesortParallel(a,mid+1,h);
        }
        merge(a,l,mid,h);
    }
}

void mergesortSerial(int a[],int l,int h){
    if(l<h){
        int mid = l+(h-l)/2;
        
        #pragma omp parallel sections
        {
            #pragma omp section
            mergesortSerial(a,l,mid);
            
            #pragma omp section
            mergesortSerial(a,mid+1,h);
        }
        merge(a,l,mid,h);
    }
}


void main(){
    int *a,num,i;
	printf("enter number:");
	scanf("%d",&num);
	a = (int *)malloc(sizeof(int)*num);
	printf("array before sorting");
	for(i=0;i<num;i++){
	       	a[i]= rand()%100;
		printf("%d ",a[i]);
	}
	double start = omp_get_wtime();
	mergesortSerial(a,0,num-1);
	double end = omp_get_wtime();
    printf("\narray after sorting\n");
	for(i =0;i<num;i++) printf("%d ",a[i]);
	double val = end - start;
	printf("\nTime for serial is:%f\n",val);

    start = omp_get_wtime();
    mergesortParallel(a,0,num-1);
    end = omp_get_wtime();
    val = end-start;
    printf("Time for parallel execution is %f\n",val);
}
