//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
Node* rev(Node *head){
        Node *cur=head;
        Node *prev=NULL;
        Node *after=NULL;
        
        while(cur!=NULL){
            after=cur->next;
            cur->next=prev;
            prev=cur;
            cur=after;
        }
        
        return prev;
    }
    Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        if(num1==NULL)
        return num2;
        
        if(num2==NULL)
        return num1;
        
        Node *temp=new Node(-1);
        Node *cur=temp;
        
        Node *l1=rev(num1);
        Node *l2=rev(num2);
        
        int carry=0;
        
        while((l1!=NULL || l2!=NULL) || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->data;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->data;
                l2=l2->next;
            }
            
            sum+=carry;
            carry=sum/10;
            
            Node *node=new Node(sum%10);
            cur->next=node;
            cur=cur->next;
        }
        
        temp=rev(temp->next);
        while(temp->data==0 && temp->next!=NULL)
        temp=temp->next;
        
        return temp;        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends