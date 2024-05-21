class Solution {
public:
    int n;
    vector<vector<int>> powerSet;
    void dfs(int idx, vector<int> subset, vector<int>& nums ){
       
        powerSet.push_back(subset);
        
        for(int i=idx; i<n; i++){
            if (i!=idx && nums[i]==nums[i-1]) continue;
            subset.push_back(nums[i]);
            dfs(i+1, subset, nums);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n=nums.size();
        dfs(0,  {}, nums);
        
        return powerSet;
    }
};