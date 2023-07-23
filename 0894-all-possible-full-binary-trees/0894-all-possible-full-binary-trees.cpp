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
    map<int, vector<TreeNode*>> dp{{1, {new TreeNode()}}};

    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if(n%2==0)
            return ans;
        
        if(dp.find(n)!=dp.end())
            return dp[n];
        
        for(int i=1;i<n;i++)
        {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n-i-1);

            for(auto l:left)
            {
                for(auto r:right)
                {
                    TreeNode* root = new TreeNode(0, l, r);
                    ans.push_back(root);
                }
            }
        }

        return dp[n] = ans;
        
    }
};