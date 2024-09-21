class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        vector<string> s;
        for(int i=1;i<=n;i++)s.emplace_back(to_string(i));
        sort(s.begin(),s.end());
        for(int i=1;i<=n;i++)ans.emplace_back(stoi(s[i-1]));
        return ans;
    }
};