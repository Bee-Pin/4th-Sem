
//SINGLY LINKED LIST
#include<stdio.h>
#include<stdlib.h>
void insert_begin();
void insert_mid();
void insert_end();
void deletion_begin();
void deletion_mid();
void deletion_end();
void display();
void prompt();
 struct node
 {
 	int info;
 	struct node *next;
 };
 struct node *head;
 
 int main()
 {
 	int choice;
 	printf("1. Insert at beginning   \n2. Insert at Middle   \n3. Insert at end   \n4. Delete at beginning   \n5. Delete at middle   \n6. Delete at end   \n7. Display   \n8. Exit\n");
 	prompt();
 }
 
 void insert_begin()
 {
 	struct node *newnode,*ptr;
 	newnode=(struct node*)malloc(sizeof(struct node));
 	int data;
 	printf("\nEnter a data to be inserted : \n");
 	scanf("%d",&data);
 	newnode-> info=data;
 	newnode->next=head;
 	head=newnode;
 	printf("\nThe inserted data is %d",newnode->info);
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
 	ptr=head;
 	for(i=0; i<pos-1;i++)
 	{
 		ptr=ptr->next;
 		if(ptr==NULL)
 		{
 			printf("\nPositon not found\n");
 			prompt();
 			
 		}
 	}
 	newnode->next=ptr->next;
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
 	}
 		printf("\nThe inserted data is %d",newnode->info);
// 		printf("\nThe node is pointing to %d",ptr);
}

void deletion_begin()
{
	struct node *ptr;
	ptr=head;
	if(head==NULL)
	{
		printf("\nList is Empty \n");
	}
	else{
		ptr=head;
	}
	head=head->next;
	printf("\nThe deleted item is %d",ptr->info);
	free(ptr);
}

void deletion_end()
{
	struct node *ptr,*temp;
	if(head==NULL)
	{
		printf("\nList is Empty\n");
		exit(0);
	}
	if(head->next=NULL){
	ptr=head;
	head=NULL;
	printf("\nDeleted item is %d",ptr->info);	
	}
	else{
		ptr=head;
		while(ptr->next!=NULL)
		{
			temp=ptr;
			ptr=ptr->next;
		}
		temp->next=NULL;
		printf("\nThe deleted item is %d",ptr->info);
		free(ptr);
	}
}

void deletion_mid()
{
	struct node *ptr,*temp;
	int pos,i;
	ptr=head;
	if(head==NULL)
	{
		printf("\nList is empty \n");
		exit(0);
	}
	printf("\nEnter the position to be deleted : ");
	scanf("%d",&pos);
	if(pos==0)
	{
		deletion_begin();
	}
	else
	{
		for(i=0;i<pos;i++)
		{
			temp=ptr;
			ptr=ptr->next;
		}
		if(ptr==NULL)
		{
			printf("\nPosition not found \n");
		}
		temp->next=ptr->next;
		printf("\nThe deleted item is %d",ptr->info);
		free(ptr);
	}
	
}
void prompt()
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
 				deletion_begin();
 				break;
 				
 			case 5:
 				deletion_mid();
 				break;
 				
 			case 6:
 				deletion_end();
 				break;
 			
 			case 7:
 				display();
 				break;
 				
 			case 8:
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
	while(ptr!=NULL)	{
		printf("%d\t",ptr->info);
		ptr=ptr->next;
	}
}
