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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count=0;
        ListNode* start=nullptr;
        ListNode* tail=nullptr;
        ListNode* result=list1;
        while(count<=b) {
            if(count==a-1) {
                start=list1;
            }
            if(count==b) {
                tail=list1->next;
            }
            count++;
            list1=list1->next;
        }
        ListNode*ptr=list2;
        while(ptr->next != nullptr) {
            ptr=ptr->next;
        }
        ptr->next=tail;
        start->next=list2;
        return result;
    }
};