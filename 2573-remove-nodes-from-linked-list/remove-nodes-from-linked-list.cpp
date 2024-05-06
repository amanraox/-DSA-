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
    ListNode* rev(ListNode* head){
         ListNode* prev,* curr,* next;
         prev=NULL,curr = head,next =head;
         while(next!=NULL){
            curr = next;
            next = curr->next;
            curr->next = prev;
            prev = curr;
         }
         return curr;
    }
     
public:
    ListNode* removeNodes(ListNode* head) {
        ios_base::sync_with_stdio(0);
        if(head == NULL || head->next == NULL)return head;
        head = rev(head);
        ListNode* prev,* head2;
        prev = head2 = head;
        int mx = 0;
        while(head!= NULL){
            if(head->val >= mx){
                if(prev!=head){
                  prev->next = head;
                  prev = head;}
                  mx = head->val;
            }
            head=head->next;
        }
        prev->next = NULL;
        return rev(head2);
    }
};