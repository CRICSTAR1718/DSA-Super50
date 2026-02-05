// Given a string s remove some characters such that every character occurs exactly once and the resultant string is lexicographically smallest such that relative order of character is maintained
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string res;
    stack<char>st;
    vector<int>freq(256,0);
    vector<bool>used(256, false);
    for(auto c:s)
    {
        freq[c]++;
    }
    for(auto c: s)
    {
        freq[c]--;
        if(used[c])
        {
            continue;
        }
        while(!st.empty() && st.top()>c && freq[st.top()]>0)
        {
            used[st.top()]=false;
            st.pop();
        }
        st.push(c);
        used[c]=true;
    }
    while(!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    cout<<res;
}