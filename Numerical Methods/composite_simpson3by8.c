#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x){
	return (1 + x*x*x);
}
int main(){
	float I, h, a, b, sol1 = 0, sol2 = 0;
	int n, i;
	printf("Input lower and higher limit: ");
	scanf("%f%f", &a, &b);
	printf("Input number of strip: ");
	scanf("%d", &n);
	h = (b - a)/3;
	for(i= 1; i<=n-1; i++){
		if(i % 3 == 0){
			sol2 = sol2 + f(a + (i * h));
		} else {
			sol1 = sol1 + f(a + (i * h));
		}
		
	}
	I = ((3 * h) / 8) * ( f(a) + (3 * sol1) + (2 * sol2) + f(b));
	printf("The result is %f.", I);
}
