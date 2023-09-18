class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& nums, int k) {
        int n=nums.size();
        int m=nums[0].size();
        vector<int> ans;
        vector<pair<int,int>> res;
        for(int i=0;i<n;i++){
            int sum = accumulate(nums[i].begin(),nums[i].end(),1);
            res.push_back({sum, i});
        }
        sort(res.begin(),res.end());
        for(int i=0;i<k;i++) ans.push_back(res[i].second);
        return ans;
    }
};