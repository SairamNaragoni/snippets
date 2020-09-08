#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_SIZE 100

int top=-1;
char arr[MAX_SIZE];

int isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}


void push(char data)
{
	if(top==(MAX_SIZE-1))
	{
		printf("Stack is full\n");
		return;
	}
	top=top+1;
	arr[top]=data;
	return;
}

void pop()
{
	if(top==-1)
	{
		printf("Stack is empty\n");
		return;
	}
	top=top-1;
	return;
}
int order(char c)
{
	if(c=='-' || c=='+')
	return 1;
	else if(c=='*' || c=='/')
	return 2;
	else if(c=='^')
	return 3;
	else 
	return 0;
}

int isoperator(char c)
{
	if(c=='-' || c=='+' || c=='*' || c=='/' || c=='^')
	return 1;
	else
	return 0;
}

int isoperand(char c)
{
	if(c>='0' && c<='9')
	return 1;
	else if(c>='a' && c<='z')
	return 1;
	else if(c>='A' && c<='Z')
	return 1;
	else
	return 0;
}

int isopening(char c)
{
	if(c=='(' || c=='{' || c=='[')
	return 1;
	else
	return 0;
}

int isclosing(char c)
{
	if(c==')' || c=='}' || c==']')
	return 1;
	else 
	return 0;
}

void main()
{
	int i,order1,order2,j=0,k;
	char infix[MAX_SIZE],postfix[MAX_SIZE];
	printf("Enter the Infix Expression\n(Specify delimiters like space or comma)\n\n");
	gets(infix);
	for(i=0;infix[i]!='\0';i++)
	{
		if(infix[i]==' ' || infix[i]==',')
		{
			postfix[j]=' ';
			j++;
		}
		else if(isoperand(infix[i]))
		{
			postfix[j]=infix[i];
			j++;
		}
		else if(isoperator(infix[i]))
		{
			if(isoperator(arr[top]))
			{
				order1=order(infix[i]);
				order2=order(arr[top]);
				while(order1<=order2)
				{						
					postfix[j]=arr[top];
					j++;
					pop();
					order2=order(arr[top]);	
				}
			}
			push(infix[i]);
		}
		else if(isopening(infix[i]))
				push(infix[i]);
		else if(isclosing(infix[i]))
			{
				while(!isopening(arr[top]))
				{
					postfix[j]=arr[top];
					j++;
					pop();
				}
				pop();
			}
	}
	while(!isempty())
	{
		postfix[j]=arr[top];
		j++;
		pop();
	}
	postfix[j]='\0';
	puts(postfix);
	return;
}
















