// 🧠 Key Idea
// Each domino covers exactly 2 squares
// The board has M × N squares total
// Dominoes cannot overlap and must be fully inside the board
// Orientation does not matter (rotation allowed)
// So the absolute maximum number of dominoes you can place is simply:
// max no of domino= m*n /2
// Why?
// Because every domino consumes 2 squares, and you can never cover more than all available squares.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>m>>n;
    cout<<(m*n)/2;
}