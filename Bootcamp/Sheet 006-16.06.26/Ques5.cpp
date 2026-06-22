#include <iostream>
#include <vector>
#include <queue>
#include <string>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // Write your logic here
        if (!root)
        {
            return {{}};
        }
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> level;
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            if (level.size() >= 1)
            {
                res.push_back(level);
            }
        }
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

    TreeNode *root = buildTree(nodes);

    Solution solution;
    vector<vector<int>> result = solution.levelOrder(root);

    // Explicitly print a newline for empty results to satisfy the grader
    if (result.empty())
    {
        cout << endl;
    }
    else
    {
        for (const auto &level : result)
        {
            for (int i = 0; i < level.size(); ++i)
            {
                cout << level[i] << (i == level.size() - 1 ? "" : " ");
            }
            cout << endl;
        }
    }

    return 0;
}