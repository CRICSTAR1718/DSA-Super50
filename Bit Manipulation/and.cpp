#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a = 24;
    int b = 16;
    int c = a & b;
    cout << c<< endl;
}

// odd=> n&1==true || n&1==1;
// even=> n&1==false || n&1==0;

// set the ith bit==>  num | (1 << i)


// clearing the ith bit==> num & ~(1<<i)  method 1

// toggling the ith bit==> num ^(1<<i)  method 2
