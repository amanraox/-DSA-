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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode();
        ListNode* temp=ans;
        int car=0;
        while(l1!=nullptr or l2!=nullptr or car)
        {
            int sum=0;
            if(l1!=NULL)
            {sum+=l1->val;l1=l1->next;}
            if(l2!=NULL)
            {sum+=l2->val;l2=l2->next;}
            sum+=car;
            car=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return ans->next;

    }
};