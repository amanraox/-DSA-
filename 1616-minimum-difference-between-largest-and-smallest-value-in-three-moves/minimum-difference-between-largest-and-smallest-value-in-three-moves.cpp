class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int a, b;
        if(n<=4)
            return 0;
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        // case one (start-1, end-2)
        a = nums[1];
        b = nums[n-3];
        ans = min(ans, b-a);

        //case 2 (s-2, e-1)
        a = nums[2];
        b = nums[n-2];
        ans = min(ans, b-a);

        //case 3 (s-3, e-0)
        a = nums[3];
        b = nums[n-1];
        ans = min(ans, b-a);

        //case 3 (s-0, 76)
        a = nums[0];
        b = nums[n-4];
        ans = min(ans, b-a);

        return ans;
    }
};