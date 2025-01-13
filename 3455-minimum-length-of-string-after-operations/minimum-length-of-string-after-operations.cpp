class Solution {
public:
    int minimumLength(string s) {
        vector <int> a(26,0);int ans=0;
        for(int i=0;i<s.length();i++)++a[s[i]-'a'];
        for(int i=0;i<26;i++)
        {
            if(a[i]>0 and a[i]&1)++ans;
            else if(a[i]>0)ans+=2;
        }
        return ans;
    }
};