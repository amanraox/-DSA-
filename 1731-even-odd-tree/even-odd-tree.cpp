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
 vector<vector<int>> levelTraversal(TreeNode* root){
        vector<vector<int>> ans;
        if(root==NULL) return ans;
     queue<TreeNode*> q;
     q.push(root);
     while(!q.empty()){
         vector<int> level;
         int n=q.size();
         for(int i=0;i<n;i++){
             TreeNode* node=q.front();
             q.pop();
             if(node->left) q.push(node->left);
             if(node->right) q.push(node->right);
             level.push_back(node->val);
         }
      ans.push_back(level);
     }
     return ans;
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>> temp=levelTraversal(root);
        int n=temp.size();
        bool x=false;
        for(int i=0;i<n;i++){
            x=!x;
            int m=temp[i].size();
            for(int j=0;j<m;j++){
           if(x==true){
             if(j==m-1) {
                 if(temp[i][j]%2==0) return false;
             }
              else if(temp[i][j]%2==0||temp[i][j]>=temp[i][j+1]) return false;
           }
           else{
                if(j==m-1) {
                 if(temp[i][j]%2!=0) return false;
             }
           else if(temp[i][j]%2!=0||temp[i][j]<=temp[i][j+1]) return false;
           }
            }
        }
        return true;
    }
};
static const int FAST__ =[](){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
return 0;
}();