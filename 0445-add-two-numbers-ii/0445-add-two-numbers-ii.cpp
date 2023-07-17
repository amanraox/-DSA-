/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
     ListNode* ReverseLL(ListNode* &head){
        if(head==NULL  ||  head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr != NULL){
            ListNode* next= curr->next;
            curr->next= prev;
            prev= curr;
            curr=next;
        }
        return prev;
    }
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=ReverseLL(l1);
        l2=ReverseLL(l2);

        ListNode* ansLL= Addition(l1,l2);

        ansLL= ReverseLL(ansLL);
        return ansLL;
    }
    void InsertAtTail(ListNode*&head, ListNode*&tail, int val){
        ListNode* temp=new ListNode(val);
        if(head==NULL){
            head= temp;
            tail=head;
            return;
        }
        else{
            tail->next=temp;
            tail=tail->next;
        }
    }
     ListNode* Addition(ListNode*first, ListNode*second){
        int carry=0;
        ListNode*head=NULL;
        ListNode*tail=NULL;

        while(first != NULL   ||   second != NULL   ||   carry != 0){
            int val1=0;
            if(first!=NULL) val1=first->val;

            int val2=0;
            if(second!=NULL) val2=second->val;

            int sum= val1 + val2 + carry;

            carry= sum/10;
            int digit= sum%10;

            InsertAtTail(head,tail,digit);

            if(first!=NULL) first=first->next; 
            if(second!=NULL) second=second->next;
        }

        return head;
    }
    
};