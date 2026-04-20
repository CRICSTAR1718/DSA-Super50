#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int val)
        {
            data = val;
            next = NULL;
            prev = NULL;
        }
};

class DoublyLinkedList
{
    private:
        Node *head;
    public:
        DoublyLinkedList()
        {
            head = NULL;
        }
        // Insert at head
        void insertAtHead(int val)
        {
            Node *newNode = new Node(val);
            if (head)
            {
                head->prev = newNode;
            }
            newNode->next = head;
            head = newNode;
        }
        // Insert at tail
        void insertAtTail(int val)
        {
            Node *newNode = new Node(val);
            if (!head)
            {
                head = newNode;
                return;
            }
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        // Delete node
        void deleteNode(int val)
        {
            if (!head)
                return;
            Node *temp = head;
            if (head->data == val)
            {
                head = head->next;
                if (head)
                    head->prev = NULL;
                delete temp;
                return;
            }
            while (temp && temp->data != val)
            {
                temp = temp->next;
            }
            if (!temp)
                return;
            if (temp->next)
                temp->next->prev = temp->prev;
            if (temp->prev)
                temp->prev->next = temp->next;
            delete temp;
        }
        void display()
        {
            Node *temp = head;
            while (temp)
            {
                cout << temp->data << " <-> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
};
