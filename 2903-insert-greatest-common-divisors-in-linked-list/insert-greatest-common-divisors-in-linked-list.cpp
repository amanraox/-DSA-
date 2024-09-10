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
int gcd(int first,int second)
{
    while(second != 0)
    {
        int temp = second;
        second = first % second;
        first = temp;
    }
    return first;
}

void insert(ListNode* prev,ListNode* forward,int data)
{
    ListNode* newNode = new ListNode(data);
    prev-> next = newNode;
    newNode-> next = forward;
}

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head-> next == NULL)
        {
            return head;
        }

        ListNode* temp = head-> next;
        ListNode* prev = head;

        while(temp != NULL)
        {
            int first = prev-> val;
            int second = temp-> val;
            int data = gcd(first,second);
            insert(prev,temp,data);
            prev = temp;
            temp = temp-> next;
        }
        return head;
    }
};