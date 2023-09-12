class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        unordered_set<int> freq;
        int res=0;
        for(auto m:mp){
            int f=m.second;
            while(f>0 && freq.find(f)!=freq.end()){
                f--;
                res++;
            }
            freq.insert(f);
        }
        return res;
    }
};