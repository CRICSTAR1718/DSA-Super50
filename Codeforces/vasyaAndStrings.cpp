#include<bits/stdc++.h>
using namespace std;
int maxBeauty(string &s, int n, int k, char ch)
{
    int left=0, changes=0, best=0;
    for(int right=0; right<n; right++)
    {
        if(s[right]!=ch)
        {
            changes++;
        }
        while(changes>k)
        {
            if(s[left]!=ch)
            {
                changes--;
            }
            left++;
        }
        best=max(best, right-left+1);
    }
    return best;
}
int main()
{
    int n, k;
    cin >> n >> k;
    string s1;
    cin >> s1;
    int beautyOnlyA=maxBeauty(s1,n,k, 'a');
    int beautyOnlyB=maxBeauty(s1,n,k, 'b');
    cout<<max(beautyOnlyA, beautyOnlyB)<<endl;
}