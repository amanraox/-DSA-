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
void f(TreeNode*root,string &ans, vector<string>&v){
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL){
        ans+=('a'+root->val);
        string x=ans;
        reverse(x.begin(),x.end());
        v.push_back(x);
        return;
    }
        ans+=('a'+root->val);
    f(root->left,ans,v);
    if(root->left)ans.pop_back();
    f(root->right,ans,v);
    if(root->right)ans.pop_back();
}
    string smallestFromLeaf(TreeNode* root) {
        string ans="";
        vector<string>v;
        f(root,ans,v);
        sort(v.begin(),v.end());
        return v[0];        
    }
};