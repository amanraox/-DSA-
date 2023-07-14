class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int N = arr.size();
        unordered_map<int, int> map;
        map[arr[N - 1]] = 0;
        int ans = 0;

        for (int i = N - 2; i >= 0; i--) {
            if (map.count(arr[i] + difference)) {
                int temp = map[arr[i] + difference] + 1;
                map[arr[i]] = temp;
                ans = max(ans, temp);
            }
            else
                map[arr[i]] = 0;
        }

        return ans + 1;
    }
};