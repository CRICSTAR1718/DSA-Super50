#include<bits/stdc++.h>
using namespace std;
int main()
{
    int w;
    cin>>w;
    // smallest even no that can divide in odd part is 2
    if(w%2==0 && w>2)
    {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    
}