class Solution
{
public:
    void mid(TreeNode *root, vector<int> &a)
    {
        if (!root)
            return;
        mid(root->left, a);
        a.push_back(root->val);
        mid(root->right, a);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> a;
        mid(root, a);
        return a;
    }
};