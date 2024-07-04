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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *dummy=new ListNode();
         ListNode* c=head->next;
         ListNode* p=dummy;
         int s=0;
        while(c)
        {
            s=0;
            while(c && c->val!=0)
            {
                s+=c->val;
                c=c->next;
            }
            p->next=new ListNode(s);
            p=p->next;
          
           if(c)
             c=c->next;

        }
        return dummy->next;
    }
};