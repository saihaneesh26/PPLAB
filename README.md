# PPLAB in C language

compilation:
> gcc -fopenmp -o file_name file_name.c

output
> ./file_name

change cores
> export OMP_NUM_THREADS=6


---------
MPI PROGMS
compilation : mpicc prgm.c
running : mpirun -n 2 ./a.out
