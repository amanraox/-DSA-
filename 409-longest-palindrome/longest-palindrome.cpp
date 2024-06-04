class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> a(126,0);bool c=1;int ans=s.length();
        for(auto i:s)++a[i];
        for(auto i:a)
        if(i==0 or i%2==0)continue;
        else if(c and (i&1)){c=0;}
        else --ans;
        return ans;
    }
};