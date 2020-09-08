//Doubly-circular Linked List
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	char roll_no[8];
	char name[20];
	float cgpa;
	struct student* next;
	struct student* prev;
};
struct student* head;
struct student* tail;
void insert()
{
	int position,value;
	char no[8];
	struct student* go=head;
	struct student* po=head;
	struct student* temp=(struct student*)malloc(sizeof(struct student));
	printf("enter the students name\n");
	scanf("%s",temp->name);
	printf("Enter the student's Roll No\n");
	scanf("%s",temp->roll_no);
	printf("Enter the student's CGPA\n");
	scanf("%f",&temp->cgpa);
	temp->next=NULL;
	temp->prev=NULL;
	printf("where do you want to insert the data\n");
	printf("1.At first\n2.Between nodes\n3.At the end\n4.Return to main menu\n\n");
	scanf("%d",&position);
	if(head==NULL)
	{	
		tail=temp;
		temp->prev=tail;
		head=temp;
		tail->next=head;
		return;
	}
	switch(position)
	{
		case 1: head->prev=temp;
			temp->next=head;
			head=temp;
			tail->next=head;
			temp->prev=tail;
			break;
		case 2: printf("Enter the Roll No after which you want to enter the data\n");
			scanf("%s",no);
			while(go!=NULL)
			{
				value=strcmp(go->roll_no,no);
				if(value==0)
				{
					po=go->next;
					temp->next=go->next;
					temp->prev=go;
					po->prev=temp;
					go->next=temp;
					return;
				}
				else
				go=go->next;
			}
			if(value!=0)
			{
				printf("Roll No doesnt exist in the List\n\n\n");
				return;
			}
			
			break;
		case 3: while(go!=tail)
			{	
				go=go->next;
			}
			temp->prev=go;
			go->next=temp;
			tail=temp;
			tail->next=head;
			head->prev=tail;	
			break;
		case 4: return;
			break;
		default: printf("Invalid Option\n\n");
			break; 
	}
}
void delete()
{

	if(head==NULL)
	{
		printf("no data to delete\n\n");
		return;
	}
	int position,value;
	char no[8];
	struct student* go=head;
	struct student* po=head;
	printf("Where do you want to delete the data\n");
	printf("1.At First\n2.In between\n3.At last\n4.Return to main menu\n\n");
	scanf("%d",&position);
	if(go->next==tail)
	{
		head=NULL;
		return;		
	}
	switch(position)
	{
		case 1: head=go->next;
			tail->next=head;
			head->prev=tail;
			break;
		case 2: printf("enter the roll no which you want to delete\n");
			scanf("%s",no);
			po=po->next;
			while((value=strcmp(po->roll_no,no))!=0)
			{
				po=po->next;
				go=go->next;
			}
			go->next=po->next;
			go->next->prev=go;				
			break;
		case 3: while(go->next!=tail)
			{
				go=go->next;
			}
			tail=go;
			head->prev=tail;
			tail->next=head;
			break;
		case 4: return;
			break;
		default:printf("invalid option\n\n");
			break;
	}
}

void search()
{
	
	if(head==NULL)
	{
		printf("There is nothing to search-List is empty\n\n");
		return;
	}
	char no[8];
	int value;
	printf("Input the roll_No you want to search\n");	
	scanf("%s",no);
	struct student* go=head;
	while(go!=NULL)
	{
		value=strcmp(go->roll_no,no);
		if(value==0)
		{
			printf("Roll_no found\n\n");
			printf("Name:%s\nRoll_No:%s\nCGPA:%f\n\n",go->name,go->roll_no,go->cgpa);
			return;
		}
		go=go->next;
	}
	if(value!=0)
	printf("Roll_No not found\n\n\n");
	return;
}
void display()
{
	struct student* temp=head;
	struct student* go=NULL;
	int choice;
	if(head==NULL)
	{
		printf("Nothing to Print-LIST is EMPTY\n\n");
		return;
	}
	printf("How do you want the List to be printed\n");
	printf("1.Forward\n2.Reverse\n3.Return to Main Menu\n\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: while(temp!=go)
			{
				printf("Name:%s\nRoll No:%s\nCGPA:%f\n\n\n",temp->name,temp->roll_no,temp->cgpa);
				temp=temp->next;
				go=head;
			}
			break;
		case 2: while(temp->next!=go)
			{
				temp=temp->next;
				go=head;
			}
			go=NULL;
			while(temp!=go)
			{
				printf("Name:%s\nRoll No:%s\nCGPA:%f\n\n\n",temp->name,temp->roll_no,temp->cgpa);
				temp=temp->prev;
				go=tail;
			}
			break;
		case 3: return;
		default: printf("Invalid Option\n\n");
			break;
	}

}

void main()
{
	head==NULL;
	int choice;
	while(1)
	{
		printf("Select your option\n");
		printf(".................MENU For Linear Doubly Linked List..................\n");
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
			default:printf("invalid option\n\n");
				break;
		}
	}
}
