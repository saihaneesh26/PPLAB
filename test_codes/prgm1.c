//sort an array of n elements using seq and merge sort
#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
void merge(int a[],int l,int mid,int h){
    int n1 = mid-l+1;
    int n2 = h-mid;

    int arr1[n1],arr2[n2];

    for(int i=0;i<n1;i++) arr1[i] = a[l+i];
    for(int i=0;i<n2;i++) arr2[i] = a[mid+1+i];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j])
        {
            a[k++] = arr1[i++];
        }
        else{
            a[k++] = arr2[j++];
        }
    }

    while(i<n1){
        a[k++] = arr1[i++];
    }
    while(j<n2){
        a[k++] = arr2[j++];
    }
}

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
        
        
        {
            
            mergesortSerial(a,l,mid);
            
            
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
