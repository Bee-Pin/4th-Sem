#include <stdio.h>
#include <math.h>
float func(float x)
{
    return (3*x*x +1);
}
int main() 
{
    float x, y, n, m1,m2,m3,m4;
    int i,count=0;
    float h, xp;
    printf("Enter the initial values of x and y :");
    scanf("%f%f", &x, &y);
    printf("Enter the step size :");
    scanf("%f", &h);
    printf("Enter xp:");
    scanf("%f", &xp);
    n = (xp - x) / h;
    for(i=1;i<=(int)n;i++){
        m1 = func(x);
        m2 = func(x+(h/2));
        m3 =  func(x+(h/2));
        m4 = func(x+h);
        y = y+(m1+2*m2+2*m3+m4)/6*h;
        x+=h;
        printf("\n%f  %f ",x,y);
        count++;
    }
    printf("\nnumber of steps : %d",count);
}
