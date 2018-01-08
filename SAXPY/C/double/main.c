#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

double SAXPY(int n, double a, double x, double y){
    int i;
    for(i=0;i<n;i++)
        y = a * x + y;
    return y;
}

int main(){
    double x[10000];
    double timer,start,end;
    int i;
    double a,y;
    FILE *file;
    srand(time(NULL));
    a = (double)rand()/RAND_MAX * (double)50.0;
    y = (double)rand()/RAND_MAX * (double)50.0;
    for(i=0;i<10000;i++)
        x[i]= (double)rand()/RAND_MAX * (double)100.0;
    file = fopen("/home/valery/Semestr/SAXPY/C/double/log_double.txt", "w");
    for(i=0;i<10000;i+=100) {
        start = omp_get_wtime();
        y = SAXPY(i, a, x[i], y);
        end = omp_get_wtime();
        timer = end - start;
        fprintf(file, "%lf\n", timer);
    }
    return 0;
}