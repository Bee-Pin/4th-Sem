#include<stdio.h>
#include<math.h>
float func(float x){
    return (3*x*x +1);
   
}
float func2(float x, float y){
    return (sin(x)+cos(y));
}
int main(){
    float x,y,n;
    int i;
    float h,xp;
    printf("Enter the initial values of x and y :");
    scanf("%f%f",&x,&y);
    printf("Enter the step size :");
    scanf("%f",&h);
    printf("Enter xp:");
    scanf("%f",&xp);
    n = (xp-x)/h;
    for(i=1;i<=(int)n;i++){
      y = y+h*func2(x,y);
      x = x+h;
      printf("\n%f  %f ",x,y);
}
  return 0;
}
