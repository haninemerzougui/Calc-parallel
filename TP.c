#include "omp.h"
#include <stdio.h>
#define N 100
int main()
{
    int a[N][N],s=0,i,j;
    double t1,t2;
    for(i=0;i<N;i++)
    for(j=0;j<N;j++)
        a[i][j]=i*4+j;
    omp_set_num_threads(4);
    t1=omp_get_wtime();
    #pragma omp parallel 
    {
        #pragma omp for reduction(+:s) private(j)
        for(i=0;i<N;i++){
        for(j=0;j<N;j++)
        s=s+a[i][j];
        //printf("PAR=%d : s=%d\n", omp_get_thread_num(),s);
        }
    }
    t2=omp_get_wtime();
    printf("SEQ s=%d  Computing time= %f\n", s,t2-t1);
return 0;
}