#include <math.h>
#include <stdio.h>


double f(double x) {

    return (10 * x + 15 * x) + ((3 + x * x));
}

int main() {
    int n = 0;
    double a, b, c, eps;
    printf("Введите интервал a ");
    scanf("%lf", &a);
    printf("Введите интервал b ");
    scanf("%lf", &b);
    printf("Введите точность ");
    scanf("%lf", &eps);
    do {
        c = (a + b) / 2;
        if (f(c) * f(a) < 0)
            a = c;
        else b = c;

        n += 1;

    } while (fabs(a - b) >= eps);
    printf("c= %lf\n", c);
    return 0;
}