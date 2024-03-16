class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int x=0;
        mp[0]=-1;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                x--;
            else
                x++;
            if(mp.find(x)!=mp.end())
                ans=max(ans,i-mp[x]);
            else
                mp[x]=i;
        }
        return ans;
    }
};