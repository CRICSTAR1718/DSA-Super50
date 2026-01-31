#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, h, l;
        cin >> n >> h >> l;
        int countH=0;
        int countL=0;
        int both=0;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if(x <= l && x <= h)
            {
                both++;
            }
            if(x <= l)
            {
                countL++;
            }
            if(x <= h)
            {
                countH++;
            }
        }
        int ans=min({countH,countL,(countH+countL-both)/2});
        cout << ans << endl;
    }
}


