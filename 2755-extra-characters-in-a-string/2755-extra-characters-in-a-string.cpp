class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int dp[51] = {}; 
        int n = s.size();
        
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1 + dp[i + 1]; 
            
            for (const auto &w : dictionary) {
                if (i + w.size() <= n && s.compare(i, w.size(), w) == 0) {
                    dp[i] = min(dp[i], dp[i + w.size()]);
                }
            }
        }
        
        return dp[0];
    }
};