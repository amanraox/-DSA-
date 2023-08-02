class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        for(int i=s.size()-1,j=0;i>=0;i--,j++)
            if(s[i]!=s[j])return 0;
        return 1;
    }
};