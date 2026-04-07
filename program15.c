// To implement Newton's Divided Difference Formula
#include <stdio.h>

int main() {
    int n, i, j;
    double x, y, term;
    double ax[50], diff[50][50];

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of x:\n");
    for(i = 0; i < n; i++) {
        scanf("%lf", &ax[i]);
    }

    printf("Enter the values of y:\n");
    for(i = 0; i < n; i++) {
        scanf("%lf", &diff[i][0]);
    }

    for(j = 1; j < n; j++) {
        for(i = 0; i < n - j; i++) {
            diff[i][j] = (diff[i+1][j-1] - diff[i][j-1]) / (ax[i+j] - ax[i]);
        }
    }

    printf("Enter the value of x to find y: ");
    scanf("%lf", &x);

    y = diff[0][0];
    term = 1;

    for(i = 1; i < n; i++) {
        term = term * (x - ax[i-1]);
        y = y + term * diff[0][i];
    }

    printf("Interpolated value at x = %lf is y = %lf\n", x, y);

    return 0;
}
