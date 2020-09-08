#include<bits/stdc++.h>
using namespace std;

long int a[100005],bits[100005];
void update(long int x,long int n)
{
    for(; x<=n; x += x&-x)
    {
        if(x==1)
        {
            bits[x]=1;
        }
        else
        {
            if(a[x-1]<a[x])
                bits[x]+=1;
        }
    }
}

void update2(long int x,long int y,long int n)
{
    for(; x<=n; x += x&-x)
    {
        if(x==1)
        {
            bits[x]=1;
        }
        else
        {
            if(y>a[x-1])
            {
                if(a[x]<a[x-1])
                {
                    bits[x]+=1;
                }
            }
            else if(y<a[x-1])
            {
                if(a[x]>a[x-1])
                    bits[x]=bits[x]-1;
            }
        }
    }
}

int query(long int x)
{
    long int sum=0;
    for(;x > 0;x-=x&-x)
    {
        sum += bits[x];
    }
    return sum;
}
void display(long int n)
{
	for(int i =1;i<=n;i++)
		cout<<bits[i]<<" ";
	cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    
        long int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++)
        {
            bits[i]=1;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            update(i,n);
            display(n);
        }
        while(q--)
        {
            long int p,x,y;
            cin>>p>>x>>y;
            if(p==1)
            {
                update2(x,y,n);
                a[x]=y;
                display(n);
            }
            else
            {
                long int r,q;
                r = query(x);
                q = query(y);
                cout<<r<<"-r"<<endl;
                cout<<q<<"-q"<<endl;
                cout<<abs(r-q)<<endl;
            }
        }
    }
    return 0;
}

