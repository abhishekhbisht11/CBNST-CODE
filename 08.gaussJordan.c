

//gauss jordan
#include <stdio.h>

int main() 
{
    int i, j, k, n;
    float A[20][20], x[10],c;

    printf("\nEnter the order of matrix: ");
    scanf("%d", &n);

    printf("\nEnter the elements of augmented matrix row-wise:\n\n");
    for (i = 1; i <= n; i++) 
    {
        for (j = 1; j <= (n + 1); j++) 
        {
            printf("A[%d][%d] : ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    // Gauss-Jordan Elimination
    for (i = 1; i <= n; i++) 
    {
        if (A[i][i] == 0.0) 
        {
            printf("Divide by zero detected!\n");
            return 1;
        }

        for (j = 1; j <= n; j++) 
        {
            if (i != j) 
            {
                c = A[j][i] / A[i][i];
                for (k = 1; k <= n + 1; k++) 
                {
                    A[j][k] =A[j][k] - c * A[i][k];
                }
            }
        }
    }

    // Normalize the diagonal elements to 1
    for (i = 1; i <= n; i++) 
    {
        float divisor = A[i][i];
        for (j = 1; j <= n + 1; j++) 
        {
            A[i][j] /= divisor;
        }
    }

    printf("Reduced row-echelon form:\n");
    for (i = 1; i <= n; i++) 
    {
        printf("\n");
        for (j = 1; j <= n + 1; j++) 
        {
            printf("%f\t", A[i][j]);
        }
    }

    printf("\nThe solution is: \n");
    for (i = 1; i <= n; i++) 
    {
        printf("\nx%d=%f\t", i, A[i][n + 1]);
    }

    return 0;
}
