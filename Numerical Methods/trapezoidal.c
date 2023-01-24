#include<stdio.h>
#include<conio.h>
float f(float x){
	return (1 + x*x*x);
}
int main(){
	float I, h;
	int a, b;
	printf("Input lower and higher limit: ");
	scanf("%d%d", &a, &b);
	h = b - a;
	I = h / 2 * ( f(a) + f(b));
	printf("The result is %f.", I);
}
