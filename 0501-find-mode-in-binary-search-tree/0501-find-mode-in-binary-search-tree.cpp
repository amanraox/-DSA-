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
void inorder(TreeNode* root,map<int,int>&mp){
        if(!root) return;
        inorder(root->left,mp);
        mp[root->val]++;
        inorder(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        map<int,int> mp;
        inorder(root,mp);
        vector<int>res;
        int maxi = 1;
        
        for(auto it:mp){
            maxi = max(maxi,it.second);
        }
        
        for(auto it:mp){
            if(it.second==maxi){
                res.push_back(it.first);
            }
		}
		return res;        
    }
};