// To implement Newton's Backward Interpolation Formula
#include <stdio.h>

int main()
{
    int i, j, n;
    double x[50], y[50][50], value, h, p, sum, term;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of x:\n");
    for(i = 0; i < n; i++)
        scanf("%lf", &x[i]);

    printf("Enter the values of y:\n");
    for(i = 0; i < n; i++)
        scanf("%lf", &y[i][0]);


    for(j = 1; j < n; j++)
    {
        for(i = n-1; i >= j; i--)
        {
            y[i][j] = y[i][j-1] - y[i-1][j-1];
        }
    }

    printf("Enter the value of x for interpolation: ");
    scanf("%lf", &value);

    h = x[1] - x[0];
    p = (value - x[n-1]) / h;

    sum = y[n-1][0];
    term = 1;
   
    for(i = 1; i < n; i++)
    {
        term = term * (p + i - 1) / i;
        sum = sum + term * y[n-1][i];
    }

    printf("Interpolated the value at x = %lf is %lf\n", value, sum);

    return 0;
}
