class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            int t = 1;
            for(int j=i;j<nums.size();j++)
            {
                t*=nums[j];
                if(t<k) ans++;
                else break;
            }
        }

        return ans;
    }
};