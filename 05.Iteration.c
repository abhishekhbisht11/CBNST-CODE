

// using iterarion method
#include <stdio.h>
#include <math.h>-
#define EP 0.00001

float findX0(float x1, float x2) {
    return (x1 + x2) / 2;
}

float f(float x) {
    return cos(x) - 3 * x - 1;
}

int main() {
    int n, i = 1;
    float x1, x2, x, x0, error;

    printf("No of iterations: ");
    scanf("%d", &n);
    printf("Enter initial values x1 and x2: ");
    scanf("%f %f", &x1, &x2);

    do 
    {
        x0 = findX0(x1, x2);
        error = fabs(f(x0));

        printf("Iteration %d: x0 = %f, f(x0) = %f\n", i, x0, error);

        if (f(x1) * f(x0) < 0) 
        {
            x2 = x0;
        } 
        
        else 
        {
            x1 = x0;
        }

        i++;

    } while (error > EP && i <= n);

    printf("Root found at x = %f\n", x0);

    return 0;
}
