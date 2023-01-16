//primes in 1-n

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int isPrime(int n){
  if(n == 0 || n == 1){
    return 0;
  }
  for(int i = 2; i <= n/2; i++){
    if(n%i == 0){
      return 0;
    }
  }
  return 1;
}

int main(){

  int x = 1,n = 100;
  int primes[100];

  double start = omp_get_wtime();
  #pragma omp parallel for
  for(int i = 1; i <= n;i++){
    if(isPrime(i)){
      int t = omp_get_thread_num();
      printf("process : %d , %d \n",t,i);
    }
  }
  double end = omp_get_wtime();
  printf("The time taken is %lf ",end - start);
  // for(int i = 0; i < n; i++){
    //If needed print numbers here from primes[i]
  // }
}
