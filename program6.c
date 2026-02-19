// To implement numerical integration using trapezoidal rule
#include <stdio.h>

double fun(double x){
	double temp = 1/(1+x*x);
	return temp;
}

int main(){
	double a, b, h, sum, result;
	int n,i;
	printf("Enter lower limit (a): ");
	scanf("%lf", &a);
	printf("Enter upper limit (b): ");
	scanf("%lf", &b);
	printf("Enter number of sub-intervals: ");
	scanf("%d", &n);
	
	if (n <= 0) {
        printf("Number of sub-intervals must be positive.");
        return 0;
    }
    
	h = (b-a)/n;
	sum = 0;
	sum = fun(a)+fun(b);
	
	for (i=1;i<n;i++) {
		sum += 2*fun(a+i*h);
	}
	
	result = sum*(h/2);
	printf("\nThe integration of the function 1/(1+x*x) in the given interval is %lf.", result );
	return 0;
}
