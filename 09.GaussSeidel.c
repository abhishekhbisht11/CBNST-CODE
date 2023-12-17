/*gauss seidel
#include <stdio.h>
#include <math.h>

#define MAX_ITER 1000
#define TOLERANCE 1e-6

int main() {
    int i, j, n;
    float A[20][20], b[20], x[20];

    printf("\nEnter the order of matrix: ");
    scanf("%d", &n);

    printf("\nEnter the elements of augmented matrix row-wise:\n\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d] : ", i + 1, j + 1);
            scanf("%f", &A[i][j]);
        }
        printf("b[%d]: ", i + 1);
        scanf("%f", &b[i]);
    }

    // Initialize the solution vector x
    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    // Gauss-Seidel Iteration
    int iter;
    for (iter = 0; iter < MAX_ITER; iter++) {
        for (i = 0; i < n; i++) {
            float sum = 0.0;

            for (j = 0; j < n; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }

            x[i] = (b[i] - sum) / A[i][i];
        }

        // Check for convergence
        int converged = 1;
        for (i = 0; i < n; i++) {
            float diff = fabs(b[i] - A[i][i] * x[i]);
            if (diff > TOLERANCE) {
                converged = 0;
                break;
            }
        }

        if (converged) {
            break;
        }
    }

    printf("Solution after %d iterations:\n", iter + 1);
    for (i = 0; i < n; i++) {
        printf("x%d = %f\n", i + 1, x[i]);
    }

    return 0;
}
*/

#include<stdio.h>
#include<math.h>

float f1(float x,float y,float z)
{
   return (44-y-2*z)/10;
}
float f2(float x,float y,float z)
{
   return (51-2*x-z)/10;
}

float f3(float x,float y,float z)
{
   return (61-x-2*y)/10;
}
int main()
{
 float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
 int itr=1;
 printf("Enter allowed error:\n");
 scanf("%f", &e);

 printf("\nCount\t\tx\t\ty\t\tz\n");
 do
 {
  
  x1 = f1(x0,y0,z0);
  y1 = f2(x1,y0,z0);
  z1 = f3(x1,y1,z0);
  printf("%d\t%f\t%f\t%f\n",itr,x1,y1,z1);

  
  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);

  itr++;

 
  x0 = x1;
  y0 = y1;
  z0 = z1;

 }while(e1>e && e2>e && e3>e);

 printf("\nSolution: x=%f, y=%f and z = %f\n",x1,y1,z1);
 return 0;
}