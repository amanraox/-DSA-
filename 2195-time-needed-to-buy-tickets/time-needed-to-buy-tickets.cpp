class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int t = tickets[k];
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            if (tickets[i] < t)
            {
                s += tickets[i];
            }
            else
            {
                if (i <= k)
                {
                    s += t;
                }
                else
                {
                    s += t -1;
                }
            }
        }
        return s;
    }
};