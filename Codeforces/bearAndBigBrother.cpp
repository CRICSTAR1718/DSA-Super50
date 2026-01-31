#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l, b;
    cin>>l>>b;
    int count =0;
    while(l<=b)
    {
        l=l*3;
        b=b*2;
        count++; 
    }
    cout<<count;
}