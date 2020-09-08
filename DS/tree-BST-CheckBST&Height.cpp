#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=data;
    return temp;
}
struct node* insert(struct node* root,int input)
{
    if(input<=root->data)
        root=insert(root->left,input);
    else if(input>root->data)
        root=root->right;
    else if(root==NULL)
    {
        root = newNode(input);
    }
    return root;
}
int findHeight(struct node* root)
{
    if(root==NULL)
    return 0;
    int lh,rh;
    lh=findHeight(root->left);
    rh=findHeight(root->right);
    return (max(lh,rh)+1);
}
int checkBST(struct node* root)
{
	if(root==NULL)
		return 1;
	if(root->data<root->left->data){
		return 0;
	}
	if(root->data>=root->right->data){
		return 0;
	}
	checkBST(root->left);
	checkBST(root->right);
	return 1;
}
int main()
{
    struct node* root;
    root=NULL;
    int n,t,height;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        root=insert(root,t);
    }
    height=findHeight(root);
    cout<<height;
    return 0;
}

