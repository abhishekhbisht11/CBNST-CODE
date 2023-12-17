//newton rephson algorithm
#include<stdio.h>
#include<math.h>
double fun(double x)
{
    return 3*x-cos(x)-1;
}

double dfun(double x)
{
    return 3+sin(x);
}
int main()
{
    double x1,x2,x,error;
    while(1)
    {
        printf("\nEnter the value of x1: ");
        scanf("%lf",&x1);
        printf("\nEnter the value of x2: ");
        scanf("%lf",&x2);
        if(fun(x1)*fun(x2)<0)
        {
            break;
        }
        else 
        {
            printf("\nInvalid Input!!");
        }
    }

    printf("Enter the accepted error: ");
    scanf("%lf",&error);
    x=(x1+x2)/2;
    int count=1;

    while(1)
    {   count++;
        x1=x-(fun(x)/dfun(x));
        if(fabs(fun(x1))<=error)
        {
            printf("\nThe final value of x is %lf",x1);
            break;
        }
        else
        {
            x=x1;
            printf("The value of function is %lf and the value of x is %lf",fun(x1),x1);
              x=x1;
        }
    }
    return 0;
}
