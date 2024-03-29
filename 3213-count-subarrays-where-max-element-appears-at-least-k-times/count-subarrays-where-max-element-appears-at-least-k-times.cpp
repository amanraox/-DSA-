class Solution {
public:
long long lessThanK(vector<int>& nums, int k, int& maxv) {
        long long ans = 0;
        int valid = 0;
        
        for (int i = 0, j = 0; j < nums.size(); j++) {
            int c = nums[j];
            
            if (c == maxv) valid++;
            
            while (i <= j and valid >= k) {
                int d = nums[i++];
                if (d == maxv) valid--;
            }
            
            if (valid < k) {
                ans += j - i + 1;
            }
        }
        
        return ans;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        int maxv = *max_element(nums.begin(), nums.end());
        long long N = nums.size();
        
        return (N * (N + 1) / 2) - lessThanK(nums, k, maxv);        
    }
};