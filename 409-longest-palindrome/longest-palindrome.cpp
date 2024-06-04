class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> a(126,0);
        for(auto i:s)
        ++a[i];
        bool c=1;
        int ans=s.length();
        for(auto i:a)
        if(i==0)continue;
        else if(c and (i&1)){c=0;}
        else if(!c and i&1)--ans;
        return ans;
    }
};