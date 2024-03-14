class Solution {
public:
int atMost(vector<int> &v, int target, int n) {
        if (target < 0) return 0;
        int i = 0, j = 0, sm = 0, ans = 0;

        while (j < n)
        {
            sm += v[j];
            while (sm > target)
            {
                sm -= v[i];
                ++i;
            }
            int cur_len = j - i + 1;
            ans += (cur_len);
            ++j;
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int N = nums.size();
        return atMost(nums, goal, N) - atMost(nums, goal-1, N);        
    }
};