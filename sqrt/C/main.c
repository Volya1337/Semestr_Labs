#include <stdio.h>

int main()
{
    double a, x;
    int i = 0;

    printf("Введите число: ");
    scanf("%lf",&a);

    x = a;
    while (x*x!=a)
    {
        x = 0.5 * (x + (a / x));
        i++;
        if (i>200)
            break;
    }
    printf("Квардратный корень из числа %f равен: %f",a,x);
    return 0;
}