//airplane queue
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 4

int rear=-1;
int front=-1;

struct plane
{
	char name[10];
};

struct plane arr[N-1];

int isempty()
{
	if(rear==-1 && front==-1)
	return 1;
	else 
	return 0;
}

int isfull()
{
	if((rear+1)%N==front)
	return 1;
	else 
	return 0;
}
void enqueue(char n[])
{
	if(isfull())
	{
		printf("The RunWay is full\n");
		return;
	}
	if(front==-1 && rear==-1)
	{
		front=front+1;
		rear=rear+1;
	}
	else
	rear=(rear+1)%N;
	strcpy(arr[rear].name,n);
	printf("The airplane to %s is on the runway\n",arr[rear].name);
	return;
}

void dequeue()
{
	if(isempty())
	{
		printf("No Airplane on the runway\n");
		return;
	}
	if(front==rear)
	{
		printf("The airplane to %s has successfully taken off\n",arr[front].name);
		front=-1;
		rear=-1;
		return;
	}
	printf("The airplane to %s has successfully taken off\n",arr[front].name);
	front=(front+1)%N;
	return;
}

void display()
{
	int f,r,c=0;
	f=front;
	r=rear;
	if(isempty())
	{
		printf("No Airplane on the runway\n");
		return;
	}
	if(front==rear && !isempty())
	{
		puts(arr[rear].name);
		return;
	}
	while(f!=(r+1)%N || isfull() &&  c<4)
	{
		puts(arr[f].name);
		f=(f+1)%N;
		c++;
	}
	return;	
}

void main()
{
	int option;
	char nam[10];
	while(1)
	{
		printf("Select an operation\n");
		printf(".........MENU..........\n");
		printf("1.Open Runway(ENQUEUE)\n2.Take Off(DEQUEUE)\n3.Display\n4.EXIT\n\n");
		scanf("%d",&option);		
		switch(option)
		{
			case 1: printf("Enter the name of route of AIRPLANE\n");
				scanf("%s",nam);
				enqueue(nam);
				break;
			case 2: dequeue();
				break;
			case 3: display();
				break;
			case 4: return;
			default: printf("Operation Failed\nPlease Try again\n\n");
				break;
		 }
	}
}
	
