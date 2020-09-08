#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int tree[2000005];

void build(int a[],int node,int start,int end)
{
    if(start==end)
    {
        tree[node] = a[start]; 
    }
    else
    {
        int mid = (start+end)/2;
        
        build(a,2*node,start,mid);
        build(a,2*node+1,mid+1,end);
        
        if(tree[2*node]<=tree[2*node+1])
        {
            tree[node]=tree[2*node];
        }
        else
        {
            tree[node]=tree[2*node+1];
        }
    }
}

void update(int a[],int node, int start, int end,int index, int value)
{
    if(start==end)
    {
        a[index]=value;
        tree[node]=value;
    }
    else
    {
        int mid = (start+end)/2;
        if(start<=index && index<=mid)
        {
            update(a,2*node,start,mid,index,value);
        }
        else
        {
            update(a,2*node+1,mid+1,end,index,value);
        }
        
        if(tree[2*node]<=tree[2*node+1])
        {
            tree[node]=tree[2*node];
        }
        else
        {
            tree[node]=tree[2*node+1];
        }
        
    }
}
void display(int a[])
{
	for(int i=1;i<=14;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int query(int a[],int node, int start, int end,int l, int r)
{
	cout<<start<<"-l"<<endl<<end<<"-r"<<endl;
    if(r<start || end<l)
    {
    	cout<<"in"<<endl;
        return 1000000;
    }
    if(l<=start && end<=r)
    {
        return tree[node];
        cout<<"innn"<<endl;
    }
    int mid = (start+end)/2;
    int x = query(a,2*node,start,mid,l,r);
    int y = query(a,2*node+1,mid+1,end,l,r);
    cout<<x<<"-x"<<endl<<y<<"-y"<<endl;
    return(min(x,y));
}
int main()
{
    int n,q,x,y;
    cin>>n>>q;
    int a[100005];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    build(a,1,1,n);
    while(q--)
    {
        char c;
        cin>>c>>x>>y;
        if(c=='q')
        {
            int ans = query(a,1,1,n,x,y);
            cout<<ans<<endl;
        }
        else
        {
            update(a,1,1,n,x,y);
            display(tree);
        }
    }
    
    return 0;
}

