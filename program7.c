//To implement numerical integration using Simpson's one-third rule
#include <stdio.h>

double fun(double x){
	double temp = 1/(1+x*x);
	return temp;
}

int main(){
	double a, b, sum, h, result;
	int n, i;
	
	printf("Enter lower limit (a): ");
	scanf("%lf",&a);
	
	printf("Enter upper limit (b): ");
	scanf("%lf",&b);
	
	printf("Enter number of intervals(even): ");
	scanf("%d",&n);
	
	while (n%2!=0){
		printf("Please enter even number of intervals: ");
		scanf("%d",&n);
	}
	
	
	h = (b-a)/n;
	sum = 0;
	sum = fun(a)+4*fun(a+h)+fun(b);
	
	for (i = 3; i<n; i+=2){
		sum+=2*fun(a+(i-1)*h)+4*fun(a+i*h);
	}
	
	result = sum*(h/3);
	printf("The numerical integration of the function 1/(1+x*x) in the given interval is: %lf ", result);
	
	return 0;
		
}
