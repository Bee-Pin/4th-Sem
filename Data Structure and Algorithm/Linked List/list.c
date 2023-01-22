#include<stdio.h>
#include<stdlib.h>

#define NUMNODES 500
int numElements=0;

struct nodetype
{
    int info, next;
};

struct nodetype node[NUMNODES];

int avail = 0; // global variable to keep track of available nodes
int x; // global variable to store the value of a deleted node

// function to get the next available node
int getnode()
{
    int p;
    if(avail == -1)
    {
        printf("No available nodes\n");
        exit(1);
    }
    p = avail;
    avail = node[avail].next;
    return p;
}

// function to free a node and add it to the list of available nodes
void freenode(int p)
{
    node[p].next = avail;
    avail = p;
}

// function to insert a new node after a given node
void insafter(int p, int x)
{
    int q;
    if(p == -1)
    {
        printf("Invalid operator\n");
        return;
    }
    q = getnode();
    node[q].info = x;
    node[q].next = node[p].next;
    node[p].next = q;
}

// function to delete the node after a given node
void delafter(int p)
{
    int q;
    if((p == -1) || (node[p].next == -1))
    {
        printf("Invalid operator\n");
        return;
    }
    q = node[p].next;
    x = node[q].info;
    node[p].next = node[q].next;
    freenode(q);
}

// function to print the contents of the linked list
void printList()
{
    int p = 0;
    while(node[p].next != -1)
    {
        printf("%d ", node[p].info);
        p = node[p].next;
    }
    printf("%d\n", node[p].info);
}

int main()
{
    int num;

    while (1)
    {
        printf("Enter a number (1-3) or 0 to exit: ");
        scanf("%d", &num);

        if (num == 0)
        {
            break;
        }

        switch(num)
        {
            case 1:
                printf("Enter the value of the element to insert: ");
                scanf("%d", &x);
                insert(numElements, x); // insert the new element at the end of the list
                break;
            case 2:
                delete(numElements-1); // delete the last element in the list
                break;
            case 3:
                printList();
                break;
            default:
                printf("Enter a number between 1 and 3\n");
        }
    }

    return 0;
}

