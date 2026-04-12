#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int cnt0 = count(s.begin(), s.end(), '0');
        int cnt1 = s.size() - cnt0;
        int length_of_t = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]=='0' && cnt1>0)
            {
                cnt1--;
                length_of_t++;
            }
            else if(s[i]=='1' && cnt0>0){
                cnt0--;
                length_of_t++;
            }
            else{
                break;
            }
        }
            int ans = s.size() -length_of_t;

        cout << ans << endl;
    }
}