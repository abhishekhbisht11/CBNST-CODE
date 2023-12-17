//newton forward difference method




//Newton Forward Interpolation
// 1. Enter the no. of observation
// 2. Enter the value of x
// 3. Enter the value of y
// 4. Newton forward Difference table
// 5. Print Difference table
// 6. Apply Newton forward Interpolation Formula


#include<stdio.h>
#include<math.h>

int main(){
    int n;
    float x;
    printf("Enter the number of the rows: ");
    scanf("%d", &n);
    printf("Enter the value of x: ");
    scanf("%f", &x);
    float a[100][100];
    for(int i =0 ;i<n;i++){
    scanf("%f",&a[i][0]);
    }
    for(int i =0 ;i<n;i++){
    scanf("%f",&a[i][1]);
    }
    for(int j = 2 ; j<=n;j++){
        for(int i = 0;i<n-j+1;i++ ){
            a[i][j] =  a[i+1][j-1] - a[i][j-1];
        }
    }
    for(int i = 0;i<n;i++){
        for (int j = 0; j <= n-i; j++)
        {   
            printf("%f ",a[i][j]);
            
        }
        printf("\n");
        
    }
    float u = (x - a[0][0])/(a[1][0]-a[0][0]);
    float u1 = u;
    float y = a[0][1];
    float fact = 1;
    for(int i = 2;i<=n;i++){
         y = y+((u1*a[0][i])/fact);
         fact  = fact*i;
         u1 = u1*(u-(i-1));
    }
    printf("The final value for f(%f) will be %f", x,y);
    return 0;
}