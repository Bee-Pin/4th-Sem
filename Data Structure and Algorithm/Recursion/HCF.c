#include<stdio.h>
int hcf(int n1,int n2)
{
    int rem;
    if(n2 != 0)
    {
        return hcf(n2,n1%n2);
    }
    else 
    {
        return n1;
    }
   
}
int main()
{
    int num1,num2;
    printf("Enter two  numbers :");
    scanf("%d%d",&num1,&num2);
    printf("The HCF of %d and %d is %d",num1,num2,hcf(num1,num2));
    return 0;
}
