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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* result=root;
        int currDepth=2;
        queue<TreeNode*>q;
        if(depth==1){
            TreeNode* firstNode=new TreeNode(val);
            firstNode->left=root;
            return firstNode;
        }
        q.push(root);
        while(currDepth<depth){
            int size=q.size();
            for(int i=0;i<size;i++){
                root=q.front();
                q.pop();
                if(root->right!=nullptr) q.push(root->right);
                if(root->left!=nullptr) q.push(root->left);
            }
            currDepth+=1;
        }
        while(!q.empty()){
            root=q.front();
            TreeNode* leftToAdd= new TreeNode(val);
            TreeNode* rightToAdd=new TreeNode(val);
            if (root->left!=nullptr){
                TreeNode* leftNode=root->left;
                root->left=leftToAdd;
                leftToAdd->left=leftNode;
            }
            else{
                root->left=leftToAdd;
            }
            if (root->right!=nullptr){
                TreeNode* rightNode=root->right;
                root->right=rightToAdd;
                rightToAdd->right=rightNode;
            }
            else{
                root->right=rightToAdd;
            }
            q.pop();
        }
        return result;
    }
};