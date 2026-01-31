#include<bits/stdc++.h>
using namespace std;    
int main()
{
    int n, t;
    // Input number of books and time limit
    cin >> n >> t;
    // Input array of time required for each book
    vector<int>time(n);
    for(int i=0; i<n; i++)
    {
        cin>>time[i];
    }
    int timeConsumed=0;
    int maxBooks=0;
    int left=0;
    for(int right=0; right<n; right++)
    {
        timeConsumed+=time[right];
        while(timeConsumed>t)
        {
            timeConsumed-=time[left];
            left++;
        }
        maxBooks=max(maxBooks, right-left+1);
    }
    cout<<maxBooks;
}