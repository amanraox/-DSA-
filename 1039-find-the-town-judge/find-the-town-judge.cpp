class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       vector<int> countTrust(n+1, 0);

        for(const auto& judge : trust) {
            countTrust[judge[0]]--;
            countTrust[judge[1]]++;
        }

        for(int i=1; i<=n; i++) {
            if(countTrust[i]==n-1) {
                return i;
            }
        }  
        return -1;
    }
};