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
    bool isLeaf(TreeNode *node)
    {
        if (!node->left && !node->right)
        {
            return true;
        }
        return false;
    }
    void helper(TreeNode *root, int targetSum, int curr, bool &flag)
    {
        if (flag)
        {
            return;
        }
        if (!root)
        {
            return;
        }
        curr += root->val;
        if (targetSum == curr)
        {
            if (isLeaf(root))
            {
                flag = true;
                return;
            }
        }
        helper(root->left, targetSum, curr, flag);
        helper(root->right, targetSum, curr, flag);
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        // Write your logic here
        if (!root && (targetSum != 0))
        {
            return false;
        }
        // if(!root && (targetSum==0))
        // {
        //     return true;
        // }
        if (!root)
        {
            return false;
        }

        bool flag = false;
        helper(root, targetSum, 0, flag);
        if (flag)
        {
            return true;
        }
        return false;
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

    vector<string> nodes(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nodes[i];
    }

    int targetSum;
    if (!(cin >> targetSum))
        return 0;

    TreeNode *root = buildTree(nodes);

    Solution solution;
    if (solution.hasPathSum(root, targetSum))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}