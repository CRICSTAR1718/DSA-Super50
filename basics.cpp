#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> numbers = {5, 3, 8, 6, 2};
    int n = numbers.size(); 
    cout<<"Initial array size: "<<n<<endl;
    cout<<"Array elements: ";
    for(int i = 0; i < n; i++)
    {
        cout<<numbers[i]<<" ";
    }
    numbers.push_back(10); // Adding an element to the vector
    n = numbers.size(); // Updating size after push_back    
    cout<<"\nArray size after push_back: "<<n<<endl;
    cout<<"Array elements after push_back: ";
    for(int i = 0; i < n; i++)
    {
        cout<<numbers[i]<<" ";
    }
    numbers.pop_back(); // Removing the last element
    n = numbers.size(); // Updating size after pop_back
    cout<<"\nArray size after pop_back: "<<n<<endl;
    cout<<"Array elements after pop_back: ";    
    for(int i = 0; i < n; i++)
    {
        cout<<numbers[i]<<" ";
    }
}