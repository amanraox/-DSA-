class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>v;
        int i,j=100001;
        for(i=0;i<nums.size();i++){
            if(nums[(nums[i]%j)-1]>j) v.push_back(nums[i]%j);
            nums[(nums[i]%j)-1]=nums[(nums[i]%j)-1]+j; }
        return v;
    }
};