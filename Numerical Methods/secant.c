#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
float fun(float x){
	return (4*sin(x)-exp(x));
}
int main(){
	int n=0;
	float x0, x1, x2, E;
	printf("Enter two initial point: ");
	scanf("%f%f", &x0, &x1);
	printf("STOPPING CRITERIA: ");
	scanf("%f", &E);
	printf("S.N.\t x0\t\tx1   \t\tx2 \n");
	do{
		x2 = x1-(((x1-x0)/(fun(x1)-fun(x0)))*fun(x1));
		x0 =x1;
		x1 =x2;	
		n++;
		printf("%d\t%f\t%f\t%f\n", n, x0, x1,x2);
	} while(fabs((x1-x0)/x1) > E);
	printf("ROOT: %f", x2);
	printf("\nCOUNT: %d",n);
}
