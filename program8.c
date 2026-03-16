//To implement numerical integration using Simpson's three-eighth rule
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
	
	printf("Enter number of intervals(multiple of 3): ");
	scanf("%d",&n);
	
	while (n%3!=0){
		printf("Please enter multiple of 3 intervals: ");
	scanf("%d",&n);
	}
	
	
	h = (b-a)/n;
	sum = 0;
	sum = fun(a)+fun(b);
	
	for (i = 1; i<n; i++){
		if (i%3==0){
			sum+=2*fun(a+i*h);
	    }
	    else{
	    	sum+=3*fun(a+i*h);
		}
		
	}
	
	result = sum*(3*h/8);
	printf("The numerical integration of the function 1/(1+x*x) in the given interval is: %lf ", result);
	
	return 0;
	
	
}
