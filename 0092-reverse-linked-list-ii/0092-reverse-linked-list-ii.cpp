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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right||head==NULL||head->next==NULL){
            return head;
        }
            int n=right-left;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=dummy;
        for(int i=0;i<left-1;i++){
            prev=prev->next;
        }
ListNode* curr=prev->next;
ListNode* nex;
while(n--){
    nex=curr->next;
    curr->next=nex->next;
    nex->next=prev->next;
    prev->next=nex;
}
        return dummy->next;
    }
};