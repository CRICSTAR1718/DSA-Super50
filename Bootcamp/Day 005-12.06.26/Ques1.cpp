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
ListNode *insertAtEnd(ListNode *head, int val)
{
    // Write your logic here
    ListNode *newNode = new ListNode(val);
    if (!head)
    {
        return newNode;
    }
    ListNode *curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->next = nullptr;
    return head;
}
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n;
    if (!(cin >> n))
        return 0;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ListNode *newNode = new ListNode(x);
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

    int valToInsert;
    cin >> valToInsert;

    ListNode *originalHead = head;
    ListNode *returnedHead = insertAtEnd(head, valToInsert);

    // Strict validation: The head should only change if the initial list was empty.
    if (originalHead != nullptr && returnedHead != originalHead)
    {
        cout << "Error: Original head node altered. You must return the same head node for non-empty lists." << endl;
    }
    else
    {
        printList(returnedHead);
    }

    return 0;
}