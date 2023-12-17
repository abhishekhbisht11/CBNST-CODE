
//secant method

#include<stdio.h>
#include<math.h>
#define ep 0.00001

float findValAt(float x) {
    return x * x * x - 5 * x + 1;
}

float findX(float x1, float x2) {
    return (x1 * findValAt(x2) - x2 * findValAt(x1)) / (findValAt(x2) - findValAt(x1));
}

int main() {
    int i = 1, maxitr;
    float x1, x2, x;

    printf("Enter the values of x1 and x2: ");
    scanf("%f %f", &x1, &x2);
    
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxitr);

    x = findX(x1, x2);

    do {
        x1 = x2;
        x2 = x;

        x = findX(x1, x2);

        printf("Iteration: %d, root: %f\n", i, x);

        if (fabs(x - x2) < ep || i >= maxitr) {
            printf("The final root is: %f\n", x);
            break;
        }
        
        i++;
    } while (1);

    return 0;
}

