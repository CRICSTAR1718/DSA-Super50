// Factorial 
// #include<bits/stdc++.h>
// using namespace std;
// int factorial(int n)
// {
//     if(n==0 || n==1)
//     {
//         return 1;
//     }
//     return n * factorial(n - 1);
// }
// int main()
// {
//     cout << "Factorial: ---->" << endl;
//     cout << "Enter any number: ";
//     int n;
//     cin >> n;
//     cout << "The factorial of given number is: "<< factorial(n);
// }



// Fibonacci
// #include <bits/stdc++.h>
// using namespace std;
// int fibonacci(int n)
// {
//     if (n == 1)
//     {
//         return 0;
//     }
//     if (n == 2)
//     {
//         return 1;
//     }
//     return fibonacci(n-1) + fibonacci(n-2);
// }
// int main()
// {
//     cout << "Fibonacci: ---->" << endl;
//     cout << "Enter value of n to find nth term: ";
//     int n;
//     cin >> n;
//     cout << "The "<<n<<"th term of Fibonacci Series is: " << fibonacci(n);
// }



// Power
#include<bits/stdc++.h>
using namespace std;
int power(int x, int n)
{
    if(n==1)
    {
        return x;
    }
    return x * power(x, n - 1);
}
int main()
{
    int x;
    cin >> x;
    int n;
    cin >> n;
    cout << power(x, n);
}