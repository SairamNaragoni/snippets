#include <bits/stdc++.h>
using namespace std;
pair<int , pair<int,int> > v[100004];
int id[100004];

int root(int x)
{
    while(id[x]!=x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
void union1(int x,int y)
{
    int p = root(x);
    int q = root(y);
    id[p]=id[q];
}

int kruskal(pair<int , pair<int,int> > v[],int m)
{
    int x,y;
    int cost,mincost=0;
    for(int i=0;i<m;i++)
    {
        x = v[i].second.first;
        y = v[i].second.second;
        cost = v[i].first;
        if(root(x)!=root(y))
        {
            mincost +=cost;
            union1(x,y);
        }
    }
    return mincost;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int x,y,w;
    for(int i=0;i<100003;i++)
        id[i]=i;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        v[i] = make_pair(w,make_pair(x,y));
    }
    sort(v,v+m);
    int mincost = kruskal(v,m);
    cout<<mincost<<endl;
    return 0;
}

