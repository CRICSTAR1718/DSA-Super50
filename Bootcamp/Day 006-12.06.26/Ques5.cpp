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
    void helper(TreeNode *root, int targetSum, int curr, vector<int> path, vector<vector<int>> &res)
    {
        if (!root)
        {
            return;
        }
        path.push_back(root->val);
        curr += root->val;
        if (targetSum == curr)
        {
            if (isLeaf(root))
            {
                res.push_back(path);
                return;
            }
        }
        helper(root->left, targetSum, curr, path, res);
        helper(root->right, targetSum, curr, path, res);
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        // Write your logic here
        vector<vector<int>> res;
        vector<int> path;
        helper(root, targetSum, 0, path, res);
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

        if (i < nodes.size() && nodes[i] != "null")
        {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

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
    vector<vector<int>> result = solution.pathSum(root, targetSum);

    // Explicitly print a newline for empty results to satisfy the grader
    if (result.empty())
    {
        cout << endl;
    }
    else
    {
        sort(result.begin(), result.end());
        for (const auto &path : result)
        {
            for (int i = 0; i < path.size(); ++i)
            {
                cout << path[i] << (i == path.size() - 1 ? "" : " ");
            }
            cout << endl;
        }
    }

    return 0;
}