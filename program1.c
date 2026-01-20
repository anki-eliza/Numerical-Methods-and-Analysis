// To display the absolute error, relative error and percentage error
#include <stdio.h>
#include <math.h>

int main() {
    double true_value, measured_value,absolute_error, relative_error, percentage_error;

    printf("Enter the true value: ");
    scanf("%lf", &true_value);

    printf("Enter the measured value: ");
    scanf("%lf", &measured_value);

    absolute_error = fabs(true_value - measured_value);
    relative_error = absolute_error / true_value;
    percentage_error = relative_error * 100;

    printf("\nAbsolute Error = %lf", absolute_error);
    printf("\nRelative Error = %lf", relative_error);
    printf("\nPercentage Error = %lf %%", percentage_error);

    return 0;

}
