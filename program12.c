// To implement Gauss Backward Interpolation Formula
#include <stdio.h>

int main() {
    int n, i, j, k;
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
        for(i = n - 1; i >= j; i--) {
            diff[i][j] = diff[i][j-1] - diff[i-1][j-1];
        }
    }

    printf("Enter the value of x to find y: ");
    scanf("%lf", &x);

    i = n - 1;
    while(x < ax[i] && i > 0) {
        i--;
    }

    p = (x - ax[i]) / h;

    y = diff[i][0];
    double term = 1;

    for(k = 1; k < n; k++) {

        if(k == 1)
            term *= p;
        else if(k % 2 == 0)
            term *= (p + k/2);
        else
            term *= (p - k/2);

        term /= k;

        y += term * diff[i][k];
    }

    printf("Interpolated value at x = %lf is y = %lf\n", x, y);

    return 0;
}
