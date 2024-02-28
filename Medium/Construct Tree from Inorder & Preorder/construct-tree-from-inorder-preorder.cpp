//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        if(n==0) return nullptr;
        if(n==1) return new Node(in[0]);
        stack<Node *>stk;
        Node *root=new Node(pre[0]);
        int preInd=1,curr=0;
        stk.push(root);
        while(preInd<n){
            Node *currNode=nullptr;
            while(!stk.empty() && stk.top()->data==in[curr]){
                currNode=stk.top();
                stk.pop();
                curr++;
            }
            Node *newnode=new Node(pre[preInd]);
            if(currNode){
                currNode->right=newnode;
            }
            else {
                stk.top()->left=newnode;
            }
            stk.push(newnode);
            preInd++;
        }return root;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends