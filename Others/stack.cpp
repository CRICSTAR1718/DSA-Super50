#include<bits/stdc++.h> 
using namespace std;    
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    // if(!st.empty()) {
    //     cout << "Top element is: " << st.top() << endl;
    // }
    // else{
    //     cout << "Stack is empty" << endl;
    // }
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}

