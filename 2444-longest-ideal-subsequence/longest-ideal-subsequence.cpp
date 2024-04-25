class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26,0);
        for(int i=0;i<s.length();i++)
        {
            int x=0;
            for(int j=max(0,s[i]-'a'-k);j<=min(25,s[i]-'a'+k);j++)
            {
                x=max(x,1+dp[j]);
            }
            dp[s[i]-'a']=x;
        }
        return *max_element(dp.begin(),dp.end());
    }
};