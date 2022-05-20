#include "omp.h"
#include <stdio.h>
int main()
{
    omp_set_dynamic(0);
    int x=0;
    #pragma omp parallel private(x)
    {
        x=x+1;
        printf("x= %d, calcule par le thread %d\n",x,omp_get_thread_num());
        int y=x+1;
        printf("y= %d, calcule par le thread %d\n",y,omp_get_thread_num());
    }
}