class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        
        vector<int> cntr(3, 0);
        for (char c : s) cntr[c - 'a']++;
        
        for (int i = 0; i < 3; i++) {
            if (cntr[i] < k) return -1;
        }
        
        int n = s.size();
        vector<vector<int>> prefix(3, vector<int>(n + 1, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                prefix[j][i + 1] = prefix[j][i] + (s[i] - 'a' == j ? 1 : 0);
            }
        }
        
        auto isValid = [&](int minutes) -> bool {
            for (int left = 0; left <= min(minutes, n); left++) {
                int right = minutes - left;
                if (right < 0 || right > n) continue;
                
                int rightStart = n - right;
                bool valid = true;
                for (int i = 0; i < 3; i++) {
                    int count = prefix[i][left] + (prefix[i][n] - prefix[i][rightStart]);
                    if (count < k) {
                        valid = false;
                        break;
                    }
                }
                if (valid) return true;
            }
            return false;
        };
        
        int left = k * 3, right = n,ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};