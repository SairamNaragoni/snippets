//linear singly linked list
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	char roll_no[8];
	char name[20];
	float cgpa;
	struct student* next;
};
struct student* head;
void insert()
{
	int position;
	char no[8];
	int value;
	struct student* temp=(struct student*)malloc(sizeof(struct student));
	printf("Enter the student's name\n");
	scanf("%s",temp->name);
	printf("Enter the student's Roll No\n");
	scanf("%s",temp->roll_no);
	printf("Enter the student's CGPA\n");
	scanf("%f",&temp->cgpa);
	printf("where do you want to insert the data\n");
	printf("1.At first\n2.Between nodes\n3.At the end\n4.Return to main menu\n");
	scanf("%d",&position);
	if(head==NULL)
	{
		temp->next=head;
		head=temp;
		return;
	}
	switch(position)
	{
		case 1: temp->next=head;
			head=temp;
			break;
	
		case 2: printf("enter the roll no after which you want to enter the data\n");
			scanf("%s",no);
			struct student* go=head;
			while(go!=NULL)
			{
				value=strcmp(go->roll_no,no);
				if(value==0)
				{
					temp->next=go->next;
					go->next=temp;
					return;
				}
				else
				go=go->next;
			}
			if(value!=0)
			{
				printf("Roll No doesnt exist in the List\n");
				return;
			}
			

			break;
			
		case 3:	 temp->next=NULL;
			struct student* temp1=head;
			while(temp1->next!=NULL)
			{
				temp1=temp1->next;
			}
			temp1->next=temp; 
			break;

		case 4: return;
			break;
		default: printf("Invalid option\n");
			break;			
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
	char no[8];
	struct student* go=head;
	struct student* po=head;
	printf("Where do you want to delete the data\n");
	printf("1.At First\n2.In between\n3.At last\n4.Return to main menu\n");
	scanf("%d",&position);
	switch(position)
	{
		case 1: head=go->next;
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
			break;
		case 3:	po=po->next;
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
			free(po);
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
		printf("Name:%s\nRoll No:%s\nCGPA:%f\n\n",temp->name,temp->roll_no,temp->cgpa);
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
	char no[8];
	int value;
	printf("Input the roll No you want to search\n");	
	scanf("%s",no);
	struct student* go=head;
	while(go!=NULL)
	{
		value=strcmp(go->roll_no,no);
		if(value==0)
		{
			printf("Roll no found\n");
			printf("Name:%s\nRoll No:%s\nCGPA:%f\n\n",go->name,go->roll_no,go->cgpa);
			return;
		}
		go=go->next;
	}
	if(value!=0)
	printf("Roll  No not found\n");
	return;
}	
		
	
void main()
{
	int choice;
	head=NULL;
	while(1)
	{
		printf("Enter your Choice\n");
		printf("...........MENU For linear Singly Linked List...........\n");
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
			case 4:search();
				break;
			case 5:exit(1);
				break;
			default:printf("invalid option\n");
				break;
		}
	}
}
