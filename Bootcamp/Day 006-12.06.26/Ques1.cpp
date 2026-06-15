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
    void helper(TreeNode *root, vector<int> &res)
    {
        if (!root)
        {
            return;
        }
        res.push_back(root->val);
        helper(root->left, res);
        helper(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        // Write your logic here
        vector<int> res;
        helper(root, res);
        return res;
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
    if (!(cin >> n))
        return 0;

    if (n == 0)
    {
        cout << endl;
        return 0;
    }

    vector<string> nodes(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nodes[i];
    }

    TreeNode *root = buildTree(nodes);

    Solution solution;
    vector<int> result = solution.preorderTraversal(root);

    // Print the result array space-separated
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}