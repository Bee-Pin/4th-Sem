#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 6
int stack[MAXSIZE];
int isfull();
int isempty();
void push();
void pop();
void peek();
void display();
int top=-1;
int x,data;
int main()
{
	int choice;
	printf("1.Push\n2.Pop\n3.Peek \n4.Display");
	printf("\nEnter your choice: ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			peek();
			break;
		case 4:
			display();
			break;
		case 5:
			exit(0);
		default:
			printf("\nEnter correct statement.");
	}
	return 0;
}

int isfull()
{
	if(top==MAXSIZE-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isempty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push()
{
	if(isfull()==1)
	{
		printf("\nStack Overflow");	
		exit(0);
	}
	else
	{
		top=top+1;
		printf("\nEnter the data: ");
		scanf("%d",&data);
		stack[top]=data;
		main();
	}
}

void pop()
{
	if(isempty()==1)
	{
		printf("\nStack underflow");
		exit(0);
	}
	else
	{
		x=stack[top];
		top--;
		printf("\nThe deleted item is %d\n",x);
		main();	
	}
}

void peek()
{
	if(isempty()==1)
	{
		printf("\nStack underflow");
		exit(0);
	}
	else
	{
		printf("\nThe top element is %d\n",stack[top]);
		main();
	}
}

void display()
{
	if(isempty()==1)
	{
		printf("\nNULL");
		exit(0);
	}
	else
	{
		int i;
		printf("\nThe elements in stack are :\n");
		for(i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
		main();
	}
}
