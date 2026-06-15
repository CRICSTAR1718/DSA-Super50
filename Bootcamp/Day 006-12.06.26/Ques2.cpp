#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/*
Sample structure of the TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
*/
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // Write your logic here
        if (!p && !q)
        {
            return true;
        }
        if (!p || !q)
        {
            return false;
        }
        if (p->val != q->val)
        {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
TreeNode *buildTree(const vector<string> &nodes)
{
    if (nodes.empty() || nodes[0] == "null")
        return nullptr;

    TreeNode *root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        // Left child
        if (i < nodes.size() && nodes[i] != "null")
        {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != "null")
        {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main()
{
    int n;
    // Read first tree
    if (!(cin >> n))
        return 0;
    vector<string> nodesP(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nodesP[i];
    }

    // Read second tree
    int m;
    if (!(cin >> m))
        return 0;
    vector<string> nodesQ(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> nodesQ[i];
    }

    TreeNode *p = buildTree(nodesP);
    TreeNode *q = buildTree(nodesQ);

    Solution solution;
    if (solution.isSameTree(p, q))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}