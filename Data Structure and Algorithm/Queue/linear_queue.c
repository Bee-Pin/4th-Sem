//linear queue
#include<stdio.h>
#include<stdlib.h>
#define size 50
int front = 0;
int rear = -1;
int queue[size];
void insertion();
void deletion();
void displays();
int main()
{
    int choice;
    
    while(1)
    {
    printf("\nEnter your choice: ");
    printf("1.Insertion   2.Deletion   3.Display    4.Exit\n");
    scanf("%d",&choice);
	
    switch(choice)
    {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            displays();
            break;
        case 4:
            exit(0);
//            break;
        default:
            printf("Please input validate choice");
            break;

    }
    }
}
void insertion()
{
    if(rear == size -1)
    {
        printf("The queue is full");
    }
    else
    {
        int value;
        printf("Enter the value: ");
        scanf("%d",&value);
        rear++;
        queue[rear] = value;
    }
}
void deletion()
{
    if(front > rear)
    {
        printf("The queue is empty");
    }
    else
    {
        printf("The deleted element is %d",queue[front]);
        front++;
    }
}

void displays()
{
    if(front > rear)
    {
        printf("The queue is empty");
    }
    else
    {
    	int i;
        printf("The elemet in queue are:\n");
        for( i = front; i <= rear; i++)
        {
            printf("%d\t",queue[i]);
        }
    }
}
