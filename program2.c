//To find out the root of the algebraic and transcendental operations using bisection method

 #include <stdio.h>
 #include <math.h>
 double f(double x){
    double y= (x*x*x - (4*x) + 1);
    return y;
 }
 int main(){
    double x1,x2,x0,err;
    printf("Enter variables x1 and x2: ");
    scanf("%lf %lf",&x1,&x2);

    printf("Enter maximum possible error: ");
    scanf("%lf",&err);



    if (f(x1)*f(x2)>=0){
        printf("Bisection method not applicable. ");
    }
    
    while ( 1 ){
        x0=(x1+x2)/2;

        if ( f(x0)*f(x1)<0){
            x2=x0;
        }

        else{
            x1=x0;
        }

        if ( ((fabs((x1-x2)/x1))< err) || f(x0)==0){
            printf("The root is %lf ",x0);
            break;
        }
        

    }

    return 0;

    

 }

 
