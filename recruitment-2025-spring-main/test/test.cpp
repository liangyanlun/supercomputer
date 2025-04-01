#include<stdio.h> 
#include<omp.h>
#include<windows.h>
static long num_steps = 100000;   
double step; 
#define NUM_THREADS 4 
int main () 
{ int i ;  double pi, sum[NUM_THREADS] , start_time, end_time ; 
step = 1.0/(double) num_steps; 
omp_set_num_threads(NUM_THREADS) ;
start_time=omp_get_wtime();
 #pragma omp parallel
 {  
int id; double x;
 id = omp_get_thread_num(); 
for (i=id, sum[id]=0.0;i< num_steps; i=i+NUM_THREADS)
{ 
x = (i+0.5)*step;   sum[id] += 4.0/(1.0+x*x); 
} 
} 
for(i=0, pi=0.0;i<NUM_THREADS;i++) pi += sum[i] * step; 
end_time=omp_get_wtime();
 printf("Pi=%f\n Running time \n", pi, end_time-start_time);
 return 0;
 }