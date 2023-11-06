class Solution {
public:
    vector<int> findLonely(vector<int>& a) {
        vector<int> ans;
        int nu[1000002]={0};
        for(auto i:a)
        nu[i]++;
        for(auto i:a)
        {
            if(nu[i]==1 and (!i or !nu[i-1]) and !nu[i+1])
            ans.push_back(i);
        }
            return ans;
    }
};