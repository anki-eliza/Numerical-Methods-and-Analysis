// To find the root of an algebraic equation using Regula Falsi method

#include <stdio.h>
#include <math.h>

double f(double x) {
    return (x*x*x - 4*x + 1);
}

int main() {
    double x1, x2, x0, f1, f2, f0;
    int iter = 0;

    printf("Enter initial guesses x1 and x2: ");
    scanf("%lf %lf", &x1, &x2);

    f1 = f(x1);
    f2 = f(x2);

    if (f1 * f2 > 0) {
        printf("Invalid interval: Root not bracketed.\n");
        return 0;
    }

    do {
        iter++;

        x0 = (x1*f2 - x2*f1) / (f2 - f1);
        f0 = f(x0);

        if (f0 * f1 < 0) {
            x2 = x0;
            f2 = f0;  
        }
        else {
            x1 = x0;
            f1 = f0;
        }
        printf("For iteration %d, the value of the function is %lf and the approximate root is %lf\n", iter,f0,x0);


    } while (fabs(f0) > 0.001);

    

    return 0;
}


