// To find the roots of any function using Newton Raphson method upto 3 significant figures

#include <stdio.h>
#include <math.h>

double f(double x){
    return (x*x*x - 4*x + 1);
}

double df(double x){
    return (3*x*x - 4);
}

int main(){
	
    double x0, x1, f0, f1, df0, err, error;
    int iter = 0;

    printf("Enter the initial guess x0: ");
    scanf("%lf", &x0);

    printf("Enter maximum permissible error: ");
    scanf("%lf", &err);

    do{
    	iter++;
    	f0 = f(x0);
    	df0 = df(x0);
        x1 = x0 - f0/df0;
        f1 = f(x1);
        error = fabs(x1 - x0);

        printf("For iteration %d, the value of the function is %lf and the approximate root x = %.6lf\n", iter, f1, x1);

        x0 = x1;

    } while(error > err);
    
    printf("\nAfter %d iterations, the approximate root upto 3 significant figures is %.3lf",iter,x1);

    return 0;
}

