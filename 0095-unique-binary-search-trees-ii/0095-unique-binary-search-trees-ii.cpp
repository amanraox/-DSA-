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
    vector<TreeNode*> solve(int left,int right,vector<int>&store)
    {
        if(left>right)
        {
            return {NULL};
        }   
        vector<TreeNode*> ans;
        for(int i=left;i<=right;i++)
        {
            vector<TreeNode*>store_left=solve(left,i-1,store);
            vector<TreeNode*>store_right=solve(i+1,right,store);
            for(auto it_left : store_left)
            {
                for(auto it_right : store_right)
                {
                    TreeNode* root= new TreeNode(store[i],it_left,it_right);
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<int> store;
        for(int i=1;i<=n;i++)
        store.push_back(i);
        return solve(0,n-1,store);
    }
};