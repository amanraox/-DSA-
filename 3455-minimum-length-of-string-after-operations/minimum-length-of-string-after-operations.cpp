class Solution {
public:
    int minimumLength(string s) {
        vector<int> a(26,0);int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ++a[s[i]-'a'];
        }
        for(int i=0;i<26;i++)
        {
            if(a[i]&1)ans++;
            if(a[i]%2==0 and a[i]>0) ans+=2;
        }
        return ans;
    }
};