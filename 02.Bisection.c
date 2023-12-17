

#include <stdio.h>
#include <math.h>

double fun(double x) 
{
    return x*x*x-(5*x)+1;
}

int main() 
{
    double x, x1, x2, error;
    
    while (1) 
    {
        printf("\nEnter the value of x1: ");
        scanf("%lf", &x1);
        printf("\nEnter the value of x2: ");
        scanf("%lf", &x2);
        
        if (fun(x1) * fun(x2) < 0) 
        {
            break;
        } 
        else 
        {
            printf("\nInvalid Input!! \n Please Try Again!");
        }
    }
    
    printf("Enter the valid error: ");
    scanf("%lf", &error);
    
    int count = 1;
    
    while (1) 
    {
        count++;
        x=(x1+x2)/2;
        if (fabs(fun(x)) <= error) 
        {
            printf("\nThe final value of X is %lf", x);
            break;
        }
         else if (fun(x) * fun(x1) < 0) 
        {
            printf("\nThe value of X is %lf (|f(X)|) in count is %d", x, count);
            x2 = x;
        } else if (fun(x) * fun(x2) < 0) 
        {
            printf("\nThe value of X is %lf (|f(X)|) in count is %d", x, count);
            x1 = x;
        }
    }
    
    return 0;
}