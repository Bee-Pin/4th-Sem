
//DOUBLY LINKED LIST
#include<stdio.h>
#include<stdlib.h>
void insert_begin();
void insert_mid();
void insert_end();
void del_begin();
void del_mid();
void del_end();
void display();
void choose();
 struct node
 {
 	int info;
 	struct node *next;
 	struct node *prev;
 };
 struct node *head=NULL;
 
 int main()
 {
 	printf("1. Insert at beginning   \n2. Insert at Middle   \n3. Insert at end   \n4. Delete at beginning   \n5. Delete at middle   \n6. Delete at end   \n7. Display   \n8. Exit\n");
 	choose();
 	return 0;
 }
 
 void insert_begin()
 {
 	struct node *newnode,*ptr;
 	newnode=(struct node*)malloc(sizeof(struct node));
 	int data;
 	printf("\nEnter a data to be inserted : \n");
 	scanf("%d",&data);
 	newnode-> info=data;
 	newnode->prev=NULL;
 	newnode->next=NULL;
 	if(head==NULL)
 	{
 		head=newnode;
		printf("\nThe inserted data is %d",newnode->info);
	}
	else
	{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
	}
 	
 }
 
 void insert_mid()
 {
 	struct node *newnode,*ptr;
 	newnode=(struct node*) malloc (sizeof(struct node));
 	int i,data,pos;
 	printf("\nEnter a data to be inserted : \n");
 	scanf("%d",&data);
 	printf("\nEnter the position where data is to be inserted : \n");
 	scanf("%d",&pos);
 	newnode->info=data;
 	newnode->prev=NULL;
 	newnode->next=NULL;
 	ptr=head;
 	for(i=0; i<pos-1;i++)
 	{
 		ptr=ptr->next;
 		if(ptr==NULL)
 		{
 			printf("\nPositon not found. Choose again \n");
 			choose();	
 		}
 	}
 	newnode->next=ptr->next;
 	newnode->prev=ptr;
 	ptr->next->prev=newnode;
 	ptr->next=newnode;
 }
 
 void insert_end()
 {
 	struct node *newnode,*ptr;
 	newnode=(struct node*) malloc (sizeof(struct node));
 	int i,data,pos;
 	printf("\nEnter a data to be inserted : \n");
 	scanf("%d",&data);
 	newnode->info=data;
 	newnode->prev=NULL;
 	newnode->next=NULL;
 	if(head==NULL)
 	{
 		head=newnode;
 		exit(0);
 	}
 	else{
 		ptr=head;
 		while(ptr->next!=NULL)
 		{
 			ptr=ptr->next;
 		}
 		ptr->next=newnode;
 		newnode->prev=ptr;
 	}
 		printf("\nThe inserted data is %d",newnode->info);
}

void del_begin()
{
	struct node *ptr;
	ptr=head;
	if(head==NULL)
	{
		printf("\nList is Empty \n");
	}
	else
	{
		ptr=head;
	}
	head=head->next;
	head->prev=NULL;
	printf("\nThe deleted item is %d",ptr->info);
	free(ptr);
}

void del_end()
{
	struct node *ptr,*temp;
	if(head==NULL)
	{
		printf("\nList is Empty\n");
		exit(0);
	}
	else if(head->next==NULL)
	{
		ptr=head;
		head=NULL;
		printf("\nDeleted item is %d",ptr->info);
		free(ptr);	
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->prev->next=NULL;
		printf("\nThe deleted item is %d",ptr->info);
		free(ptr);
	}
}

void del_mid()
{
	struct node *ptr,*temp;
	int pos,i;
	printf("\nEnter the position to be deleted : ");
	scanf("%d",&pos);
	ptr=head;
	if(head==NULL)
	{
		printf("\nList is empty \n");
		exit(0);
	}
	
	else if(pos==0)
	{
		head=head->next;
		head->prev=NULL;
		printf("The deleted item is %d",ptr->info);
		free(ptr);
	}
	else
	{
		for(i=0;i<pos;i++)
		{
			ptr=ptr->next;
	
			if(ptr==NULL)
			{
				printf("\nPosition not found \n");
				return;
			}
		}
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
		printf("\nThe deleted item is %d",ptr->info);
		free(ptr);
	}
	
}
void choose()
{
	while(1)
 	{
 		int choice;
 		printf("\nEnter your choice : \n");
 		scanf("%d",&choice);
 		switch (choice )
 		{
 			case 1:
 				insert_begin();
 				break;
 			
 			case 2:
 				insert_mid();
 				break;
 				
 			case 3:
 				insert_end();
 				break;
 				
 			case 4:
 				del_begin();
 				break;
 				
 			case 5:
 				del_mid();
 				break;
 				
 			case 6:
 				del_end();
 				break;
 			
 			case 7:
 				display();
 				break;
 				
 			case 8:
 				printf("\nThe program is successfully terminated.\n");
 				exit(0);
 				
 			default:
 				printf("\nEnter a choice between 1-8 only\n");
 				break;
 		}
 	}	
}
void display()
{
	struct node*ptr;
	ptr=head;
	int i;
	printf("\nThe elements in the list are : ");
	while(ptr!=NULL)	
	{
		printf("%d\t",ptr->info);
		ptr=ptr->next;
	}
}
 
