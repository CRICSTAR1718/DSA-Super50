#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    unordered_set<char>st;
    for(auto it: s)
    {
        st.insert(it);
    }
    if(st.size()%2!=0)
    {
        cout<<"IGNORE HIM!"<<endl;
    }
    else{
        cout<<"CHAT WITH HER!"<<endl;
    }
}