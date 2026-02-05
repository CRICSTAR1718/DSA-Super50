#include<bits/stdc++.h> 
using namespace std;
int main()
{
    queue<int> q;
    int n;
    cout<<"Enter number of elements in queue:"<<endl;
    cin>>n;
    cout<<"Enter elements of queue:"<<endl;
    int x;
    while(n--)
    {
        cin>>x;
        q.push(x);
    }
    cout<<"Element at the front is: "<<q.front();
}




