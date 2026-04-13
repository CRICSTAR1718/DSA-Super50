#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> freq(26, 0);
        int c = 0;
        for(char c: s)
        {
            freq[c - 'a']++;
        }
        for(int f: freq)
        {
            if(f%2)
            {
                c++;
            }
        }
        if(c<=k+1)
        {
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
}