//evaluation of postfix expression
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

int top=-1;
int arr[100];

void push(int data)
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

int isoperator(char c)
{
	if(c=='-' || c=='+' || c=='*' || c=='/')
	return 1;
	else
	return 0;
}

int isoperand(char c)
{
	if(c>='0' && c<='9')
	return 1;
	else
	return 0;
}

int operation(int a,int b,char c)
{
	if(c=='*')
	return a*b;
	else if(c=='-')
	return a-b;
	else if(c=='/')
	return a/b;
	else if(c=='+')
	return a+b;
}

void main()
{
	int i,c,op1,op2,op3,d,e,j;
	char postfix[100];
	printf("Enter the Postfix Expression\n(Specify delimiters like space or comma)\n\n");
	gets(postfix);
	for(i=0;postfix[i]!='\0';i++)
	{	
		if(postfix[i]==' ' || postfix[i]==',')
		continue;
		else if(isoperand(postfix[i]))
		{
			if(isoperator(postfix[i+2]) || isoperator(postfix[i+1]))
			{
				c=postfix[i]-'0';
				push(c);
			}
			else
			{
				d=0;
				while(isoperand(postfix[i]) && postfix[i]!='\0')
				{
					d=d*10+(postfix[i]-'0');
					i++;
				}
				push(d);
			}
		}
		else if(isoperator(postfix[i]))
		{	
			op2=arr[top];
			pop();
			op1=arr[top];
			pop();
			op3=operation(op1,op2,postfix[i]);	
			push(op3);
		}
	}
	printf("%d\n",arr[top]);
	return;
}


