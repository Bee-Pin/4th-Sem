
//question 1
	#include<stdio.h>
	#include<math.h>
	//x^2 - 4x - 10;
	float fvalue(x){
		float temp; 
		temp = (x*tan(x) - 1);
		return temp;
	}
	int main(){
		float f1,f2,E,xo,fo;
		float x1,x2;
		int count = 1;
		printf("enter the stopping criteria");
		scanf("%f",&E);
guess:
		printf(" enter your initial guess :");
		scanf("%f%f",&x1,&x2);
		f1 = fvalue(x1);
		f2 = fvalue(x2);
		if((f1*f2)>0){
			printf(" invalid guess , guess again");
			goto guess;
		}
			printf(" x1 \t\t x2 \t\t xo \t\t fo \n");
			
			
			do {
				xo = (x1+x2)/2;
				fo = fvalue(xo);
			
			if((fo*f1)> 0){
				x1 = xo;

			}
			else {
			x2 = xo;
			}
			count ++;
			printf( "%f\t%f\t%f\t%f\n",x1,x2,xo,fo);
		}   while (fabs((x2-x1)/x2) > E);

	printf(" \n the root is %f and number of steps are : %d",xo,count);
}
