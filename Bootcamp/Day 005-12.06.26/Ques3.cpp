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
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *nextNode = nullptr;
        while (curr)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // Write your logic here
        ListNode *head1 = reverse(l1);
        ListNode *head2 = reverse(l2);
        ListNode *dummy = new ListNode(0);
        ListNode *res = dummy;
        int carry = 0;
        while (head1 && head2)
        {
            int v1 = head1->val;
            int v2 = head2->val;
            int v = v1 + v2 + carry;
            carry = v / 10;
            res->next = new ListNode(v % 10);
            res = res->next;
            head1 = head1->next;
            head2 = head2->next;
        }
        while (head1)
        {
            int v = head1->val + carry;
            carry = v / 10;
            res->next = new ListNode(v % 10);
            head1 = head1->next;
        }
        while (head2)
        {
            int v = head2->val + carry;
            carry = v / 10;
            res->next = new ListNode(v % 10);
            head2 = head2->next;
        }
        if (carry)
        {
            res->next = new ListNode(carry);
        }
        ListNode *head = reverse(dummy->next);
        delete dummy;
        return head;
    }
};
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode *buildList(int size)
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    for (int i = 0; i < size; ++i)
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
    return head;
}

int main()
{
    int n, m;

    // Build first list
    if (!(cin >> n))
        return 0;
    ListNode *l1 = buildList(n);

    // Build second list
    if (!(cin >> m))
        return 0;
    ListNode *l2 = buildList(m);

    // Call user function and print
    Solution solution;
    ListNode *result = solution.addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}