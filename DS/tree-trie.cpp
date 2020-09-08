#include <iostream>
#include<bits/stdc++.h>
#include<string.h>

using namespace std;
struct node{
    struct node* child[36];
    bool isend;
    int pcount;
}*root;


struct node* getnode()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    memset(temp->child,NULL,sizeof(temp->child));
    temp->isend=false;
    temp->pcount=0;
    return temp;
}

void insert(string s)
{
    struct node* current = root;
    current->pcount++;
    for(int i=0;i<s.length();i++)
    {
        int letter = (int)s[i]-(int)'a';
        if(letter < 0)
            letter = letter+75;
        if(current->child[letter]==NULL)
        {
            current->child[letter] = getnode();
        }
        current->child[letter]->pcount++;
        current=current->child[letter];
    }
    current->isend=true;
}

int count_words(string s)
{
    struct node* current = root;
    for(int i=0;i<s.length();i++)
    {
        int letter = (int)s[i]-(int)'a';
        if(letter < 0)
            letter = letter+75;
        if(current->child[letter]==NULL)
            return 0 ;
        else
            current = current->child[letter];
    }
    return current->pcount;
}
bool search(string s)
{
    struct node* current = root;
    for(long int i=0;i<s.length();i++)
    {
    	int letter = (int)s[i]-(int)'a';
    	if(letter<0)
    	letter = letter + 75;
        if(current->child[letter]==NULL)
            return false;
        current = current->child[letter];
    }
    return current->isend;
}



int main()
{
	root = (struct node*)malloc(sizeof(struct node));
	memset(root->child,NULL,sizeof(root->child));
    root->isend = false;
    root->pcount=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	string s;
    	int ec;
        cin>>s;
        int l = s.length();
        string temp = s;
        for(int j=l-1;isdigit(temp[j]);j--)
        {
            temp.resize(temp.size()-1);
        }
        cout<<temp<<endl;
        ec = count_words(temp);
        cout<<ec<<"-ec"<<endl;
        if(ec==0)
        {
        	insert(s);
            cout<<s<<endl;
        }
        else
        {
            ec=ec-1;
            char b = ec+48;
            temp = temp+b;
            cout<<temp<<endl;
            insert(temp);
        }          
    }
    return 0;
}

