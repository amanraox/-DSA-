class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        int n=a.size();
        vector<int> b=a;
        unordered_map<int,int> v;
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        
        for(int i=0;i<b.size();i++)
        v[b[i]]=i+1;
        for(int i=0;i<n;i++)
        a[i]=v[a[i]];
        return a;
    }
};