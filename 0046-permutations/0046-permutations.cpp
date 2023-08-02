class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
       int n=nums.size();
        int Mask=(1<<n)-1;
        vector<vector<int>> ans;
        function<void(int, vector<int>&)> backtrack=[&](int mask, vector<int>& cur){
            if (mask==Mask){
                ans.push_back(cur);
                return;
            }
            for (int i=0; i<n; i++){
                if ((mask&(1<<i))==0){
                    cur.push_back(nums[i]);
                    backtrack(mask|(1<<i), cur);
                    cur.pop_back();
                }
            }
        }; 
        vector<int> cur;
        backtrack(0, cur);
        return ans; 
    }
};