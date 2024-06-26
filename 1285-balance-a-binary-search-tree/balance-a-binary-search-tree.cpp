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
    vector<TreeNode*> currentNodes;

    TreeNode* balanceBST(TreeNode* root) {
        preOrder(root);
        return balance(0, currentNodes.size() - 1);
    }

private:
    TreeNode* balance(int i, int j) {
        if (i > j)
            return nullptr;

        int mid = i + (j - i) / 2;
        TreeNode* res = currentNodes[mid];
        res->left = balance(i, mid -1);
        res->right = balance(mid + 1, j);
        return res;
    }

    void preOrder(TreeNode* root) {
        if (root == nullptr)
            return;

        preOrder(root->left);
        currentNodes.push_back(root);
        preOrder(root->right);
        
    }
};