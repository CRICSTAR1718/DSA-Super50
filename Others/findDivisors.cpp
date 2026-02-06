#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; 
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"The factors are: ";
    for(int i=1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            cout<<i<<" ";
            if(n/i != i)
            {
                cout<<n/i<<" ";
            }
        }
    }
    cout<<endl;
}