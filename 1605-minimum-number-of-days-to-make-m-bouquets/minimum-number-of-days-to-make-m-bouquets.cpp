class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int left = 0;
        int right = 1e9;
        int ans = -1;

        while(left <= right)
        {
            int mid= left + (right - left)/2;
            int count = 0;
            int j = 0;
            for(int i=0;i<n;i++)
            {
                if(bloomDay[i] <= mid)
                {
                    j++;

                }
                else
                {
                    j=0;
                }
                if(j == k)
                {
                    j = 0;
                    count++;
                }
            }
            if(count >= m)
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};