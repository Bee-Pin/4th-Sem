#include<stdio.h>
 #include<conio.h>
 #include<graphics.h>
 void main()
 {
   float xc,yc,rx,ry,x,y,p;
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"C:\\turboc3\\BGI");
   printf("Enter Xc=");
   scanf("%f",&xc);
   printf("Enter Yc=");
   scanf("%f",&yc);
   printf("Enter Rx=");
   scanf("%f",&rx);
   printf("Enter Ry=");
   scanf("%f",&ry);
   x=0;
   y=ry;
   p=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
   while((2*x*ry*ry)<(2*y*rx*rx))
   {    delay(50);
	putpixel(xc+x,yc-y,WHITE);
	putpixel(xc-x,yc+y,WHITE);
	putpixel(xc+x,yc+y,WHITE);
	putpixel(xc-x,yc-y,WHITE);

	if(p<0)
	{
     x=x+1;     y=y;
     p=p+(2*ry*ry*x)+(ry*ry);
	}
	else
	{
     x=x+1;
     y=y-1;
     p=p+(2*ry*ry*x+ry*ry)-(2*rx*rx*y);
	}
   }
       p=((ry*ry)*((x+0.5)*(x+0.5))+(rx*rx)*((y-1)*(y-1))-((rx*rx)*(ry*ry)));

	 while(y>=0)
   {    delay(50);
	putpixel(xc+x,yc-y,WHITE);
	putpixel(xc-x,yc+y,WHITE);
	putpixel(xc+x,yc+y,WHITE);
	putpixel(xc-x,yc-y,WHITE);

	if(p>0)
	{
     y=y-1;
     p=p-(2*rx*rx*y)+(rx*rx);

	}
	else
	{
     y=y-1;
     x=x+1;
     p=p+(2*ry*ry*x)-(2*rx*rx*y)-(rx*rx);
	}
   }
   getch();
   closegraph();
 }
