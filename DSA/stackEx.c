#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20
int top=-1;
struct book{
	char name[20];
	char id[10];
	int price;
};
struct book stack[MAX_SIZE];
void push()
{	
	if(top==(MAX_SIZE-1))
	{
		printf("Stack is full\n");
		return;
	}
	top=top+1;
	printf("enter the book name\n");
	scanf("%s",stack[top].name);
	printf("enter the book ID\n");
	scanf("%s",stack[top].id);
	printf("enter the book price\n");
	scanf("%d",&stack[top].price);

}
void pop()
{
	if(top==-1)
	{
		printf("the stack is empty\n");
		return;
	}
	top=top-1;
	return;
}

void peep()
{
	int position;
	printf("enter the position of book which you want to peep\n");
	scanf("%d",&position);
	if(position>top)
	{
		printf("EMPTY\n");
		return;
	}
	printf("book_Name=%s\nBook_ID=%s\nBook_Price=%d\n",stack[position].name,stack[position].id,stack[position].price);
	return;
}

void display()
{
	int i;
	if(top==-1)
	{
		printf("the stack is empty\n");
		return;
	}
	for(i=top;i>=0;i--)
	{
		printf("stack[%d]\nbook_Name=%s\nBook_ID=%s\nBook_Price=%d\n\n",i,stack[i].name,stack[i].id,stack[i].price);
	}
	return;
}
	
	
void main()
{
	int choice;
while(1)
{
	printf("enter your choice\n");
	printf("..........MENU..........\n");
	printf("1.Push\n2.Pop\n3.Peep\n4.Display\n5.exit\n");
	scanf("%d",&choice);
	if(!(choice>0 && choice<6))
	{
		printf("Invalid Entry,Try Again\n");
		return;
	}
	switch(choice)
	{
		case 1:push();
			break;
			
		case 2:pop();
			break;
			
		case 3:peep();
			break;
			
		case 4:display();
			break;
			
		case 5:exit(1);
		
		default:printf("invalid option\n");
	}
}
	
}

