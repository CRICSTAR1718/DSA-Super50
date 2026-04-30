#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int coutnOpen = 0;
        int countClose = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                coutnOpen++;
            }
            else{
                countClose++;
            }
        }
        bool flag = false;
        if(coutnOpen != countClose){
            cout << "NO\n";
        }
        else{
            int b = 0;
            for(int i = 0; i < n; i++){
                if(s[i] == '('){
                    b++;
                }
                else{
                    b--;
                }
                if(b < 0){
                    flag = true;
                    break;
                }
            }
            if(b==0){
                flag = true;
            }
            if(flag){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
    }
}