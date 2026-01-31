// Given a number print binary forms of all numbers upto n
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter value of n: ";
    cin>>n;
    queue<int>q;
    q.push(1);
    cout<<"Binary representations are: ";
    while(n--)
    {
        int t=q.front();
        cout<<t<<" ";
        q.pop();
        q.push(t*10);
        q.push(t*10+1);
    }
    cout<<endl;
}