// *
// **
// ***
// ****
#include <iostream>
using namespace std;
void patternPrint(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << "*";
    patternPrint(n - 1);
}
void print(int n)
{
    if (n == 0)
    {
        return;
    }
    print(n - 1);
    patternPrint(n);
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    print(n);
    return 0;
}