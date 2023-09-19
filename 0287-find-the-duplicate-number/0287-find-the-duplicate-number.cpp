class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> mys;
        for(int i = 0; i < nums.size(); i++){
            if(mys.find(nums[i]) != mys.end()) return nums[i];
            mys.insert(nums[i]);
        }
        return 0;
    }
};