class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();     int pre=0, count=0;

        unordered_map <int,int> mp;

        for(int i=0; i<n; i++)
        {
            pre += nums[i]%2;

            if(pre==k)  count++;

            if( mp.count(pre-k) )   count += mp[pre-k];

            mp[pre]++;
        }

        return count;
    }
};