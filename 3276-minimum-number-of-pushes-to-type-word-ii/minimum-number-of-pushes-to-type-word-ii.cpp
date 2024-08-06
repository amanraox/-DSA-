class Solution {
public:
    int minimumPushes(string w) {
        vector<int> mp(26,0);
        int n=w.size(),ans=0;
        for(int i=0;i<n;i++)++mp[w[i]-'a'];
        sort(mp.rbegin(),mp.rend());
        // reverse(mp.begin(),mp.end());
        for(int i=0;i<26;i++)
        if(mp[i]==0)break;
        else if(i<8)ans+=mp[i];
        else if(i<16)ans+=mp[i]*2;
        else if(i<24)ans+=mp[i]*3;
        else ans+=mp[i]*4;
        return ans;
    }
};