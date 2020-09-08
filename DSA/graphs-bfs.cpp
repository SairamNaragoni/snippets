#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
        vector<int> v[10000];
        int x,y;
        
        for(int i=0;i<b;i++)
        {
            cin>>x>>y;
            v[y].push_back(x);
            v[x].push_back(y);
        }
        queue<int> q;
        int level[10000];
        bool vis[10000];
        memset(vis,false,sizeof(vis));
        vis[0]=true;
        level[0]=0;
        q.push(0);
        while(!q.empty())
        {
            int z = q.front();
            q.pop();
            cout<<"hai"<<endl;
            for(int i=0;i<v[z].size();i++)
            {
            	cout<<"
                if(v[z][i]==false)
                {
                    q.push(v[z][i]);
                    level[v[z][i]] = 1+level[z];
                    vis[v[z][i]]=true;
                    cout<<"level"<<v[z][i]<<level[v[z][i]]<<endl;
                }
            }
        }
        for(int i=1;i<a;i++)
        {
            cout<<level[i]<<endl;
        }
    return 0;
}

