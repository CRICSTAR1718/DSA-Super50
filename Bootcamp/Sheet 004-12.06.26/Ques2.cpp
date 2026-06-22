#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
/*
Sample structure of the ListNode:
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
*/
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // Write your logic here
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    int n;
    if (!(cin >> n))
        return 0;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    vector<ListNode *> nodes;

    // Build the linked list
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ListNode *newNode = new ListNode(x);
        nodes.push_back(newNode);

        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Read the loop index and connect the tail
    int pos;
    if (cin >> pos)
    {
        if (pos >= 0 && pos < n && tail != nullptr)
        {
            tail->next = nodes[pos];
        }
    }

    // Instantiate the user's class and call their method
    Solution solution;
    if (solution.hasCycle(head))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}