//To find the roots of any function x*x*x-4*x+1 using Fixed Point Iteration method upto 3 significant figures

#include <stdio.h>
#include <math.h>

double f(double x){
	return (pow(x, 3)- 4*x + 1);
}
//Option 1
double phi1(double x) {
    return (pow(x, 3) + 1.0) / 4.0;
}

double dphi1(double x) {
    return (3.0 * pow(x, 2)) / 4.0;
}

//Option 2
double phi2(double x) {
    return cbrt(4.0 * x - 1.0);
}

double dphi2(double x) {
    return 4.0 / (3.0 * pow(4.0 * x - 1.0, 2.0/3.0));
}

//Option 3
double phi3(double x) {
    return -sqrt(4.0 - (1.0 / x));
}

double dphi3(double x) {
    return -1.0 / (2.0 * pow(x, 2) * sqrt(4.0 - (1.0 / x)));
}


int main() {
    double a, b;
    int iter = 0;
    double tolerance = 0.0005;

    printf("Enter initial guess a: ");
    scanf("%lf", &a);
    b = a;
    
    
    if (fabs(dphi1(a)) < 1){
    	
    	do{ 
    	    b = a;
		    iter++;
			a = phi1(a);
			
			printf("For iteration %d, the approximate root is %lf and the value of function is %lf\n", iter, a, f(a));
			
			if(fabs(a-b) < tolerance){
				break;
			}
		}
		
		while (iter < 100);
		
		printf("\nAfter %d iterations, the approximate root correct upto 3 significant figures is %.3g", iter, a);
    
	}
	
	else if (fabs(dphi2(a)) < 1){
    	
    	do{ 
    	    b = a;
		    iter++;
			a = phi2(a);
			
			printf("For iteration %d, the approximate root is %lf and the value of function is %lf\n", iter, a, f(a));
			
			if(fabs(a-b) < tolerance){
				break;
			}	
		}
		
		while (iter < 100);
		
		printf("\nAfter %d iterations, the approximate root correct upto 3 significant figures is %.3g", iter, a);
    
	}
	
	else if (fabs(dphi3(a)) < 1){
    	
    	do{ 
    	    b = a;
		    iter++;
			a = phi3(a);
			
			printf("For iteration %d, the approximate root is %lf and the value of function is %lf\n", iter, a, f(a));
			
			if(fabs(a-b) < tolerance){
				break;
			}
		}
		
		while (iter < 100);
		
		printf("\nAfter %d iterations, the approximate root correct upto 3 significant figures is %.3g", iter, a);
    
	}
	
	else {
		printf("Fixed point iteration method fails to converge for this initial guess. ");
	}
	
	return 0;
}

    

    
    

