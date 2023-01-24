#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x){
	return (1 + x*x*x);
}
int main(){
	float I, h, a, b;
	printf("Input lower and higher limit: ");
	scanf("%f%f", &a, &b);
	h = (b - a)/3;
	I = ((3 * h) / 8) * ( f(a) + (3 * f(a+h)) + (3 * f(a+ (2*h))) + f(b));
	printf("The result is %f.", I);
}
