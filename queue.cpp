// print first N natural numbers in sorted ordere whose digit belong to[1,2,3], N=10

#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int>q;
    q.push(0);
    int n;
    cout<<"Enter value of n: ";
    cin>>n;
    vector<int>ans;
    while(ans.size()<n)
    {
        int t=q.front();
        if(t>0)
        {
            ans.push_back(t);
        }
        q.pop();
        q.push(t*10+1);
        q.push(t*10+2);
        q.push(t*10+3);
    }
    cout<<"The elements in increasing order: ";
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;

}