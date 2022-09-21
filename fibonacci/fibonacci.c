#include<stdio.h>
#include<omp.h>

int fib(int n){
  if(n==0||n==1)
    return 1;

  return fib(n-1)+fib(n-2);
}

void main(){
  #pragma omp parallel
  {
    int t = omp_get_thread_num();
    printf("Thread T=%d : %d\n",t,fib(35+t));
  }
}
