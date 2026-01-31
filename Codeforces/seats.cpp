// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cin>>n; 
//         string s;
//         cin>>s;
//         int existing=0;
//         for(char c: s)
//         {
//             if(c=='1')
//             {
//                 existing++;
//             }
//         }
//         int add=0;
//         int i=0;
//         while(i<n)
//         {
//             if(s[i]=='0' && (i==0 || s[i-1]=='0') && (i==n-1 || s[i+1]=='0'))
//             {
//                 add++;
//                 s[i]='1';
//                 i+=2;
//             }
//             else{
//                 i++;
//             }
//         }
//         cout<<existing+add<<endl;
//     }
// }


// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         string s;
//         cin >> s;
//         int ones = 0;
//         for (char c : s) if (c == '1') ones++;
//         int add = 0;
//         for (int i = 0; i < n; ) {
//             if (s[i] == '1') {
//                 i++;
//                 continue;
//             }
//             int j = i;
//             while (j < n && s[j] == '0') j++;
//             int len = j - i;
//             bool left = (i > 0 && s[i - 1] == '1');
//             bool right = (j < n && s[j] == '1');
//             if (!left && !right) {
//                 // whole string is zeros
//                 add += (len) / 2;
//             }
//             else if (left && right) {
//                 // between two ones
//                 add += max(0, (len - 1) / 2);
//             }
//             else {
//                 // touches one end
//                 add += (len-1) / 2;
//             }
//             i = j;
//         }
//         cout << ones + add << "\n";
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int existing = 0;
        for (char c : s) if (c == '1') existing++;
        int add = 0;
        for (int i = 0; i < n; ) {
            if (s[i] == '1') {
                i++;
                continue;
            }
            int j = i;
            while (j < n && s[j] == '0') j++;
            int L = j - i;
            int blocked = 0;
            if (i > 0 && s[i - 1] == '1') blocked++;
            if (j < n && s[j] == '1') blocked++;
            int effective = L - blocked;
            if (effective > 0)
                add += (effective + 2) / 3; 
            i = j;
        }
        cout << existing + add << "\n";
    }
    return 0;
}


