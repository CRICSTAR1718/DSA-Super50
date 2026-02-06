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
        vector<int>arr(n);
        int evenPosOddVals=0;
        int oddPosEvenVals=0;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            if(i%2==0 && arr[i]%2 !=0)
            {
                evenPosOddVals++;
            }
            else if(i%2!=0 && arr[i]%2 ==0)
            {
                oddPosEvenVals++;
            }
        }
        if(evenPosOddVals==oddPosEvenVals)
        {
            cout<<evenPosOddVals<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}