#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i=1;
        while(n>0)
        {
            int r=sqrt(i);
            if(r*r==i)
            {
                cout<<i<<" ";
                n--;
            }
            i++;
        }
        cout<<endl;
    }
}