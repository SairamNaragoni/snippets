//Ordered singly linear linked list
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	int roll_no;
	char name[20];
	float cgpa;
	struct student* next;
};
struct student* head;

void insert()
{
	char no[8];
	int value=0;
	struct student* temp=(struct student*)malloc(sizeof(struct student));
	printf("Enter the student's name\n");
	scanf("%s",temp->name);
	printf("Enter the student's Roll No\n");
	scanf("%d",&temp->roll_no);
	printf("Enter the student's CGPA\n");
	scanf("%f",&temp->cgpa);
	if(head==NULL)
	{
	   head=temp;
	   temp->next=NULL;
	   return;
	}
	struct student* go=head;
	struct student* po=head;
	if(temp->roll_no>go->roll_no && go->next==NULL)
	{
		go->next=temp;
		temp->next=NULL;
		return;
	}
	go=go->next;
	
	while(go!=NULL && go->roll_no<temp->roll_no)
	{
		go=go->next;
		po=po->next;
	}
	if(po==head)
	{
		temp->next=head;
		head=temp;
		return;
	}
	else if(po->next==NULL)
	{
		temp->next=NULL;
		po->next=temp;
		return;
	}
	else
	{
		temp->next=po->next;
		po->next=temp;
		return;
	}
}

void delete()
{
	if(head==NULL)
	{
		printf("no data to delete\n");
		return;
	}
	int position,value;
	int no;
	struct student* go=head;
	struct student* po=head;
	printf("Where do you want to delete the data\n");
	printf("1.At First\n2.In between\n3.At last\n4.Return to main menu\n");
	scanf("%d",&position);
	switch(position)
	{
		case 1: head=go->next;
			break;
		case 2: printf("enter the roll_no which you want to delete\n");
			scanf("%d",&no);
			po=po->next;
			while(po->roll_no!=no && po->next!=NULL)
			{
				po=po->next;
				go=go->next;
			}
			if(po->next==NULL)
			{
				printf("roll_no Not found\n\n");
				return;
			}
			go->next=po->next;				
			break;
		case 3: po=po->next;
			if(po==NULL)
			{
				head=NULL;
				return;
			}
			while(po->next!=NULL)
			{
				po=po->next;
				go=go->next;
			}
			go->next=NULL;
			break;
		case 4: return;
			break;
		default:printf("invalid option\n");
			break;
	}
}

void display()
{
	struct student* temp=head;
	if(head==NULL)
	printf("list is empty\n\n");
	while(temp!=NULL)
	{
		printf("Name:%s\nRoll_No:%d\nCGPA:%f\n\n",temp->name,temp->roll_no,temp->cgpa);
		temp=temp->next;
	}
	return;
}
void search()
{
	if(head==NULL)
	{
		printf("There is nothing to search-List is empty\n");
		return;
	}
	int no;
	int value=0;
	printf("Input the roll_No you want to search\n");	
	scanf("%d",&no);
	struct student* go=head;
	while(go!=NULL)
	{
		
		if(go->roll_no==no)
		{
			printf("Roll_no found\n");
			printf("Name:%s\nRoll No:%d\nCGPA:%f\n\n",go->name,go->roll_no,go->cgpa);
			value=1;
			return;
		}
		go=go->next;
	}
	if(value!=1)
	printf("Roll_No not found\n");
	return;
}	
		
	
void main()
{
	int choice;
	head=NULL;
	while(1)
	{
		printf("Enter your Choice\n");
		printf("...........MENU For ordered linear Singly Linked List...........\n");
		printf("1.Insertion\n2.Deletion\n3.Display\n4.search\n5.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();
				break;
			case 2:delete();
				break;
			case 3:display();
				break;
			case 4: search();
				break;
			case 5:exit(1);
				break;
			default:printf("invalid option\n");
				break;
		}
	}
}
