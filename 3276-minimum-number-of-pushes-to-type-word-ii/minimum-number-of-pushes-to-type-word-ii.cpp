class Solution {
public:
    int minimumPushes(string w) {
        vector<int> mp(26,0);
        int n=w.size(),ans=0;
        for(int i=0;i<n;i++)++mp[w[i]-'a'];
        sort(mp.rbegin(),mp.rend());
        for(int i=0;i<26;i++)
        if(mp[i]==0)break;
        else ans+=mp[i]*(i/8+1);
        return ans;
    }
};