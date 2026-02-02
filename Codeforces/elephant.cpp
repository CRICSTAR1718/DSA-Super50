#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count=0;
    count+=n/5;
    n=n%5;
    count+=n/4;
    n=n%4;
    count+=n/3;
    n=n%3;
    count+=n/2;
    n=n%2;
    count+=n;
    cout<<count<<endl;
}