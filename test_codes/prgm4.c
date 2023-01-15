#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
//fib
int fib(int n){
    int i,j;
    if(n<2) return n;
    else{
        #pragma omp task shared(i) firstprivate(n)
        i = fib(n-1);
        
        #pragma imp task shared(j) firstprivate(n)
         j = fib(n-2);
        #pragma imp taskwait
        return i+j;
    }
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
