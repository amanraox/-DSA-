class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = 1;
        bool decreasing = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                decreasing = 0;
            } else if (nums[i] < nums[i - 1]) {
                increasing = 0;
            }

            if (!increasing && !decreasing) {
                return 0;
            }
        }
        return true;
    }
};