class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros = 0;
        int product  = 1;
        for(auto i : nums)
            if(i == 0)
                zeros++;
            else
                product *= i;

        if(zeros > 1)
        {
            vector<int> ans(nums.size(), 0);
            return ans;

        }else if(zeros == 1){
            vector<int> ans;
            for(auto i : nums)
            {
                if(i == 0)
                    ans.push_back(product);
                else
                    ans.push_back(0);
            }
            return ans;

        }else{
            vector<int> ans;
            for(auto i : nums)
                ans.push_back(product/i);

            return ans;
            
        }
    }
};