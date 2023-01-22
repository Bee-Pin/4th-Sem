//3 false
#include<stdio.h>
#include<math.h>

float fvalue(float x){
float temp;
//return  pow(x,2) - 4*x -10 ;
return (x*tan(x)-1);

}
int main() {
		float f1,f2,E,xo,fo;
		float x1,x2;
		int count = 0;
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
			while (fabs(fvalue(xo))> E) {
				xo = (x1*fvalue(fabs(x2))-x2*fvalue(fabs(x1))) / (fvalue(fabs(x2)) - fvalue(fabs(x1)));
				fo = fvalue(xo);
			
			if((fo*f1)< 0){
				x2 = xo;

			}
			else {
			x1 = xo;
			}
			count ++;
			printf( "%f\t%f\t%f\t%f\n",x1,x2,xo,fo);
	    }
		printf(" \n the root is %f and number of steps are : %d",xo,count);
}
