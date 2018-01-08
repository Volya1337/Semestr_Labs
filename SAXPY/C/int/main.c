
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int SAXPY(int n, int a, int x, int y){
    int i;
    for(i=0;i<n;i++)
        y = a * x + y;
    return y;
}

int main(){
    int x[10000];
    double timer,start,end;
    int i,a,y;
    FILE *file;

    srand(time(NULL));
    a = rand()/100;
    y = rand()/100;
    for(i=0;i<10000;i++)
        x[i] = rand()%100;
    file = fopen("/home/valery/Semestr/SAXPY/C/log_int.txt", "w");
    for (i=0;i<10000;i+=100){
        start = omp_get_wtime();
        y = SAXPY(i,a,x[i],y);
        end = omp_get_wtime();
        timer = end - start;
        fprintf(file,"%lf\n",timer);
    }
}