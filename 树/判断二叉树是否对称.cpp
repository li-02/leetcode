/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool check(TreeNode *p, TreeNode *q)
    {
        if (q == nullptr && p == nullptr)
            return true;
        if (q == nullptr || p == nullptr)
            return false;
        return (q->val == p->val) && (check(q->left, p->right)) && (check(q->right, p->left));
    }
    bool isSymmetric(TreeNode *root)
    {
        return check(root, root);
    }
};