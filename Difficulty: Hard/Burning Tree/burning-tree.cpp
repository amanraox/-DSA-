//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int target) 
    {
unordered_map<Node *, Node *> parents;
        if (root==NULL){
            return {};
        }
        queue<Node *> q;
        q.push(root);
        parents[root] = nullptr;
        Node *t;
        while(!q.empty()){
            int size = q.size();

            for (int i = 0; i < size; i++){
                Node *curr = q.front();
                q.pop();
                if (curr->data == target){
                    t = curr;
                }

                if (curr->left!=nullptr){
                    q.push(curr->left);
                    parents[curr->left] = curr;
                }

                if (curr->right!=nullptr){
                    q.push(curr->right);
                    parents[curr->right] = curr;
                }
            }
        }
        unordered_map<Node*, int> visited;
        queue<Node *> bfs;
        bfs.push(t);
        int ans = 0;
        while(!bfs.empty()){
            int size = bfs.size();
            
            for (int j = 0; j < size; j++){
                Node *curr = bfs.front();
                bfs.pop();
                visited[curr] = 1;
                if (parents[curr] != nullptr){
                    if (visited.find(parents[curr]) == visited.end()){
                        bfs.push(parents[curr]);
                    }
                }

                if (curr->left != nullptr){
                    if (visited.find(curr->left) == visited.end()){
                        bfs.push(curr->left);
                    }
                }
                if (curr->right != nullptr){
                    if (visited.find(curr->right) == visited.end()){
                        bfs.push(curr->right);
                    }
                }
            }
            ans++;
        }

        return ans-1;    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends