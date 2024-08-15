//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        Node* temp = head;
        Node* prev = NULL;
        Node* nineprev = head->data==9?head:NULL;
        while(temp->next){
            prev = temp;
            temp = temp->next;
            if(temp->data==9){
                if(!nineprev){
                    nineprev = prev;
                }
            }else{
                nineprev = NULL;
            }
        }
        temp->data +=1;
        if(nineprev==head){
            Node* temp = new Node(1);
            temp->next = head;
            while(head->next){
                head->data = 0;
                head = head->next;
            }
            return temp;
        }else if(nineprev){
            nineprev->data+=1;
            nineprev = nineprev->next;
            while(nineprev){
                nineprev->data = 0;
                nineprev = nineprev->next;
            }
        }
        return head;
        // Your Code here
        // return head of list after adding one
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends