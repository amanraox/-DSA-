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
void bfs(TreeNode* root,int &result) {
        if(root == nullptr) {
            return ;
        }
        if(root->left != nullptr && 
        root->left->right == nullptr && 
        root->left->left == nullptr) {
            result += root->left->val;
        }
        bfs(root->left,result);
        bfs(root->right,result);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int result=0;
        bfs(root,result);
        return result;
    }
};