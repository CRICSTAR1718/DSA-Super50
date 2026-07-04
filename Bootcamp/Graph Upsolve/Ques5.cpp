#include <bits/stdc++.h>
using namespace std;
int main() {
    // your code goes here
    int n,m,t;
    cin>>n>>m>>t;
    vector<vector<int>>dist(n, vector<int>(n, INT_MAX));
    for(int i=0; i<m;i++)
    {
        int u, v,w;
        cin>>u>>v>>w;
        dist[u][v] = w;
        dist[v][u] = w;
    }
    for(int i=0; i<n; i++)
    {
        dist[i][i]=0;
    }
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n;i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)
                {
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    int ans=-1;
    int count=INT_MAX;
    for(int i=0; i<n; i++)
    {
        int c=0;
        for(int j=0; j<n; j++)
        {
            if( i!=j && dist[i][j]<=t)
            {
                c++;
            }
        }
        if(c<=count)
        {
            ans=i;
            count=c;
        }
    }
    cout<<ans<<endl;
    return 0;
}