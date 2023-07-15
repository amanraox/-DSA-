class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
         sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    int n = events.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    for (int i = 1; i <= n; i++) {
        int l = 0, r = i - 1, last = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (events[mid][1] < events[i - 1][0]) {
                last = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        for (int j = 1; j <= k; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[last + 1][j - 1] + events[i - 1][2]);
        }
    }
    return dp[n][k];
    }
};