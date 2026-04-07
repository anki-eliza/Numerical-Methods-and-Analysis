//To implement Bessel's Interpolation Formula

#include <stdio.h>

int main() {

    int n, i, j;
    double x, h, p, y;
    double ax[50], ay[50], diff[50][50];

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of x:\n");
    for(i = 0; i < n; i++)
        scanf("%lf", &ax[i]);

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

    i = 0;
    while(i < n-1 && ax[i] < x) i++;
    i = i - 1;

    p = (x - ax[i]) / h;
    double y1, y2, y3, y4;
    y1 = p * diff[i][1];

    y2 = (p * (p - 1) / 2.0) *
         (diff[i][2] + diff[i-1][2]) / 2.0;

    y3 = (p * (p - 1) * (p - 0.5) / 6.0) *
         diff[i-1][3];

    y4 = ((p + 1) * p * (p - 1) * (p - 2) / 24.0) *
         (diff[i-2][4] + diff[i-1][4]) / 2.0;

    y = ay[i] + y1 + y2 + y3 + y4;

    printf("Interpolated value at x = %lf is y = %lf\n", x, y);

    return 0;
}
