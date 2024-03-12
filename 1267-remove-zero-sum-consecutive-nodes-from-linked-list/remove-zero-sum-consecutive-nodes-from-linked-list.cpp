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
ListNode* vectorToLinkedList(vector<int> vec) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (vec.size() == 0) {
            return NULL;
        }

        ListNode* head = new ListNode(vec[0],NULL);
        ListNode* current = head;

        for (int i = 1; i < vec.size(); i++) {
            ListNode* newNode = new ListNode(vec[i],NULL);
            current->next = newNode;
            current = newNode;
        }

        return head;
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(!head)return NULL;
        int sum=0;
        ListNode* curr=head;
        vector<int> presum,v;

        while(curr!=NULL){
            v.push_back(curr->val);
            sum+=curr->val;
            presum.push_back(sum);
            curr=curr->next;
        }

        for(int i=0;i<presum.size();i++){
            int x=presum[i];
            if(x==0){
                for(int j=0;j<=i;j++){
                    v[j]=INT_MAX;
                    presum[j]=INT_MAX;
                }
            }
            else{
                int s=-1;
                for(int j=0;j<i;j++){
                    if(presum[j]==x){
                        s=j+1;
                        break;
                    }
                }
                if(s!=-1){
                    for(int a=s;a<=i;a++){
                        v[a]=INT_MAX;
                        presum[a]=INT_MAX;
                    }
                }
            }
        }

        vector<int> ans;
        for(int i=0;i<v.size();i++){
            if(v[i]!=INT_MAX)ans.push_back(v[i]);
        }
        
        return vectorToLinkedList(ans);        
    }
};