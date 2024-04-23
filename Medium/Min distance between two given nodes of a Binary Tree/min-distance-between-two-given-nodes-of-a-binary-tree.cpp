//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findLevel(Node *root, int k, int level){
    if (root == NULL){
        return -1;
    }
    if (root->data == k){
        return level;
    }
    int left = findLevel(root->left, k, level + 1);
    if (left == -1){
        return findLevel(root->right, k, level + 1);
    }
    return left;
}

Node *findDistanceBetweenNodesHelper(Node *root, int node1, int node2, int level, int &d1, int &d2, int &dist){
    if (root == NULL){
        return NULL;
    }
    if (root->data == node1){
        d1 = level;
        return root;
    }
    if (root->data== node2){
        d2 = level;
        return root;
    }
    Node *left_lca = findDistanceBetweenNodesHelper(root->left, node1, node2, level + 1, d1, d2, dist);
    Node *right_lca = findDistanceBetweenNodesHelper(root->right, node1, node2, level + 1, d1, d2, dist);
    if (left_lca != NULL && right_lca != NULL){
        dist = (d1 + d2) - 2 * level;
        return root;
    }
    if (left_lca != NULL){
        return left_lca;
    }else{
        return right_lca;
    }
}
    
    int findDist(Node* root, int node1, int node2) {
        int d1 = -1;
    int d2 = -1;
    int dist = 0;
    Node* lca = findDistanceBetweenNodesHelper(root, node1, node2, 1, d1, d2, dist);
    if (d1 != -1 && d2 != -1){
        return dist;
    }
    if (d1 != -1) {
        dist = findLevel(lca, node2, 0);
        return dist;
    }
    if (d2 != -1){
        dist = findLevel(lca, node1, 0);
        return dist;
    }
    return -1;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends