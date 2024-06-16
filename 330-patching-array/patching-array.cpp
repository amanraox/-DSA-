class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum = 1;
        int ans=0;
        while(sum<=n)
        {
            long long y =0;
            for(auto i:nums)
            {
                if(i>sum)
                continue;
                y+=i;
            }
            if(y>=sum)
            {
                sum = y+1;
            }
            else
            {
                ans++;
                nums.push_back(y+1);
            }
        }

        return ans;
    }
};