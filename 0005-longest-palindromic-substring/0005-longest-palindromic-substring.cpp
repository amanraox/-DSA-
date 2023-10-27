class Solution {
public:
    string expandFromCenter(int l, int r, string s) {
        while(l >= 0 && r < s.size() && s[l] == s[r])
            l--, r++;
        return s.substr(l + 1, r - l -1);
    }
    string longestPalindrome(string s) {
        string lo = "";
        for(int i = 0; i < s.size(); i++) {
            string odd = expandFromCenter(i, i, s);
            string even = expandFromCenter(i, i + 1, s);
            if (odd.size() > lo.size()) lo = odd;
            if (even.size() > lo.size()) lo = even;
        }
        return lo;
        
    }
};