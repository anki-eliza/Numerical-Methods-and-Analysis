// To implement Gauss's Forward Interpolation Formula
#include <stdio.h>

int main() {
    int n, i, j;
    double x, h, p, y;
    double ax[50], ay[50], diff[50][50];

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of x:\n");
    for(i = 0; i < n; i++) {
        scanf("%lf", &ax[i]);
    }

    printf("Enter the values of y:\n");
    for(i = 0; i < n; i++) {
        scanf("%lf", &ay[i]);
        diff[i][0] = ay[i];
    }

    h = ax[1] - ax[0];


    for(j = 1; j < n; j++) {
        for(i = 0; i < n - j; i++) {
            diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
        }
    }


    printf("Enter the value of x to find y: ");
    scanf("%lf", &x);

    
    p = (x - ax[0]) / h;
         
    
    y = diff[0][0];
    float term = 1;

    for(i = 1; i < n; i++) {
        term = term * (p - (i - 1)) / i;
        y = y + term * diff[0][i];
    }

    printf("Interpolated value at x = %lf is y = %lf\n", x, y);

    return 0;
}
