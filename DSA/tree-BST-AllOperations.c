#include<stdio.h>
#include<stdlib.h>

struct node{
	char data;
	struct node* left;
	struct node* right;
};
int count=0;

struct node* newNode(char data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct node* insert(struct node* root,char data)
{
	
	if(root==NULL)
	{
		root=newNode(data);
		return root;
	}
	else if(data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	else if(data>root->data)
	{
		root->right=insert(root->right,data);
	}
	return root;
}

int search(struct node* root,char data)
{
	if(root==NULL)
		return 0;
	else if(root->data==data)
		return 1;
	else if(data<=root->data)
		search(root->left,data);
	else if(data>root->data)
		search(root->right,data);
}

void preorder(struct node* root)
{
	if(root==NULL)
		return;
	printf("%c ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%c ",root->data);
	inorder(root->right);
}

void postorder(struct node* root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%c ",root->data);
}

void findMin(struct node* root)
{

	if(root->left==NULL)
	{
		printf("%c",root->data);
		return;
	}
	findMin(root->left);
}

void findMax(struct node* root)
{

	if(root->right==NULL)
	{
		printf("%c",root->data);
		return;
	}
	findMax(root->right);
}

int max(int a,int b)
{
	if(a>=b)
	return a;
	else
	return b;
}

int height(struct node* root)
{
	if(root==NULL)
	return -1;
	int lh,rh;
	lh=height(root->left);
	rh=height(root->right);
	return (max(lh,rh)+1);

}
void deleteTree(struct node* root)
{
	if(root==NULL)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
	count=0;
}

struct node* min(struct node* root)
{

	if(root->left==NULL)
		return root;
	findMin(root->left);
}

struct node* delete(struct node* root , char data)
{
	if(root==NULL)
		return root;
	else if(data<root->data)
		root->left=delete(root->left,data);
	else if(data>root->data)
		root->right=delete(root->right,data);
	else 
	{
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			root=NULL;
		}
		else if(root->left == NULL)
		{
			struct node* temp=root;
			root=root->right;
			free(temp);	
		}		
		else if(root->right==NULL)
		{
			struct node* temp=root;
			root=root->left;
			free(temp);
		}
		else
		{
			struct node* temp = min(root->right);
			root->data=temp->data;
			root->right=delete(root->right,temp->data);
		}
	}
	return root;	
}


void main()
{	
	struct node* root;
	root=NULL;
	int choice,flag,h;
	char data;
	while(1)
	{	
		printf("\nEnter your choice\n");
		printf("............MENU............\n\n");
		printf("1.Insert Into Tree\n2.Search Tree\n3.PreOrder Traversal\n4.InOrder Traversal\n5.PostOrder Traversal\n6.Height of the Tree\n7.Find Min\n8.Find Max\n9.Delete a Node\n10.Delete a tree\n11.Count Nodes\n\n12.Exit\n\n");
		scanf("%d",&choice);
		if(choice!=1 && choice!=12 && count==0)
			printf("no tree is created to perform that operation\n");
		else
		{
		switch(choice)
		{

			case 1: count++;
				printf("Enter the data\n");
				scanf("%c",&data);
				scanf("%c",&data);
				root=insert(root,data);
				break;
	
			case 2: printf("Enter The Data To Be searched\n");
				scanf("%c",&data);
				scanf("%c",&data);
				flag=search(root,data);
				if(flag==0)
				printf("Data not found in the tree\n\n");
				else if(flag==1)
				printf("Data found in the tree\n\n");
				break;

			case 3: preorder(root);
				break;
	
			case 4: inorder(root);
				break;
	
			case 5: postorder(root);
				break;

			case 6: h=height(root);
				printf("The height of the Tree is %d\n",h);
				break;

			case 7: findMin(root);
				break;

			case 8: findMax(root);
				break;

			case 9: printf("Enter the data to be deleted\n");
				scanf("%c",&data);
				scanf("%c",&data);
				count--;
				root = delete(root,data);
				break;

			case 10: deleteTree(root);
				break;

			case 11: printf("No. of Nodes = %d",count);
				break;

			case 12: return;

			default: printf("Invalid Input, Try again\n");
		}
		}		
	}

}
