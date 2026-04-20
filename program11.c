// To implement Gauss's Forward Interpolation Formula
#include <stdio.h>

int main() {
    int n, i, j, k, mid;
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

    mid = n / 2;

    p = (x - ax[mid]) / h;

    y = diff[mid][0];
    double term = 1;

    for(k = 1; k < n; k++) {

        if(k == 1)
            term *= p;
        else if(k % 2 == 0)
            term *= (p - (k/2));
        else
            term *= (p + (k/2));

        term /= k;

        y += term * diff[mid - (k/2)][k];
    }

    printf("Interpolated value at x = %lf is y = %lf\n", x, y);

    return 0;
}
