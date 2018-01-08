#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

float SAXPY(int n, float a, float x, float y){
    int i;
    for(i=0;i<n;i++)
        y = a * x + y;
    return y;
}

int main(){
    float x[10000];
    double timer,start,end;
    int i;
    float a,y;
    FILE *file;
    srand(time(NULL));
    a = (float)rand()/RAND_MAX * (float)50.0;
    y = (float)rand()/RAND_MAX * (float)50.0;
    for(i=0;i<10000;i++)
        x[i] = (float)rand()/RAND_MAX * (float)100.0;
    file = fopen("/home/valery/Semestr/SAXPY/C/log_float.txt", "w");
    for(i=0;i<10000;i+=100){
        start = omp_get_wtime();
        y = SAXPY(i,a,x[i],y);
        end = omp_get_wtime();
        timer = end - start;
        fprintf(file,"%lf\n",timer);
    }
}