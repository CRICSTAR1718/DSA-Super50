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
    int dfs(TreeNode *root, int &ans)
    {
        if (!root)
        {
            return 0;
        }
        int leftSum = max(0, dfs(root->left, ans));
        int rightSum = max(0, dfs(root->right, ans));

        int curr = root->val + leftSum + rightSum;
        ans = max(ans, curr);
        return root->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode *root)
    {
        // Write your logic here
        if (!root)
        {
            return 0;
        }
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
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

    if (n == 0)
    {
        return 0;
    }

    vector<string> nodes(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nodes[i];
    }

    TreeNode *root = buildTree(nodes);

    Solution solution;
    cout << solution.maxPathSum(root) << endl;

    return 0;
}