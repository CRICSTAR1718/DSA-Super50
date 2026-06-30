#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};
Node *buildTree(vector<string> &arr)
{
    if (arr.size() == 0 || arr[0] == "null")
    {
        return nullptr;
    }
    Node *root = new Node(stoi(arr[0]));
    queue<Node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size())
    {
        Node *curr = q.front();
        q.pop();
        if (i < arr.size() && arr[i] != "null")
        {
            curr->left = new Node(stoi(arr[i]));
            q.push(curr->left);
        }
        i++;
        if (i < arr.size() && arr[i] != "null")
        {
            curr->right = new Node(stoi(arr[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
int dfs(Node *root, int &tot)
{
    if (!root)
    {
        return 0;
    }
    int leftDiff = dfs(root->left, tot);
    int rightDiff = dfs(root->right, tot);
    tot += abs(leftDiff - rightDiff);
    return leftDiff + rightDiff + root->val;
}
int main()
{
    // your code goes here
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *root = buildTree(arr);
    int tot = 0;
    int ans = dfs(root, tot);
    cout << tot << endl;
    return 0;
}