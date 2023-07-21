class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0, max_len = 0; 
        vector<int> len(n, 0), cnt(n, 0); 
        for(int i=0; i<n; i++){ 
            len[i] = cnt[i] = 1; 
            for(int j=0; j <i; j++){ 
                if(nums[i] > nums[j]){ 
                    if(len[i] == len[j] + 1) 
                        cnt[i] += cnt[j]; 
                    if(len[i] < len[j] + 1){ 
                        len[i] = len[j] + 1; 
                        cnt[i] = cnt[j]; 
                    } 
                } 
            } 
            if(max_len == len[i]) 
                res += cnt[i]; 
            if(max_len < len[i]){ 
                max_len = len[i]; 
                res = cnt[i]; 
            } 
        } 
        return res;
    }
};