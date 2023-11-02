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
     int cnt = 0;

    pair<int, int> f(TreeNode* root) {
        if(!root)return {0, 0};
        auto lsum = f(root->left);
        auto rsum = f(root->right);

        int sum = (lsum.first + rsum.first + root->val);
        int c = lsum.second + rsum.second +1;
        int avg = sum / c;
        if(avg == root->val)cnt++;
        return {sum, c};
    }

    int averageOfSubtree(TreeNode* root) {
        f(root);
        return cnt;
        
    }
};