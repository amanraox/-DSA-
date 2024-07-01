class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& a) {
        int ans=0;
        for(auto &i:a)
        {
            if(i&1)++ans;
            else ans=0;
            if(ans==3)return true;
        }
        if(ans==3)return true;
        return false;
    }
};