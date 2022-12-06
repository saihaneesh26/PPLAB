#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
//fib
int fib(int n){
    int a=0,b=1,t;
    #pragma omp parallel for  schedule(static,2) 
    for(int i=0;i<n;i++){
        #pragma omp critical
        {
            t = a+b;
            a = b;
            b = t;
        }
    }
    return a;
}
void main(){
    int n = 20;
    double start = omp_get_wtime();
    #pragma omp parallel for
    for(int i=0;i<n;i++){
        int t = omp_get_thread_num();
        printf("thread: %d fib(%d) = %d\n",t,i,fib(i));
    }
    double end = omp_get_wtime();
    printf("using schedule time is : %f\n",end-start); 

}
