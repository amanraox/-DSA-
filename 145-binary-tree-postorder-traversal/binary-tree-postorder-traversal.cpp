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
class Solution {
public:
    vector<int>a;
    void postOrder(TreeNode*root)
    {
        if(root == NULL) return;
        postOrder(root->left);
        postOrder(root->right);
        a.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) 
    {
        if(root == NULL) return a;
        postOrder(root->left);
        postOrder(root->right);
        a.push_back(root->val);
        return a;
    }
};