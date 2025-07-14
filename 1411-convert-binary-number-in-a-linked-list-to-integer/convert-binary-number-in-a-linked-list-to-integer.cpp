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
    int getDecimalValue(ListNode* head) {
        ListNode* h=head;
        string s="";
        long long ans=0;
        while(h->next!=NULL)
        {
            if(h->val==1)s+="1";
            else s+="0";
            h=h->next;
        }
        if(h->val==1)s+="1";
            else s+="0";
        reverse(s.begin(),s.end());
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')ans+=pow(2,i);
        }
        cout<<s;
        return ans;
    }
};