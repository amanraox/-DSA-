class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>>sol;
        for(int i=1;i<=n;i++){
            vector<int> ans;
            for(int j=0;j<n;j++){
                if(ans.size() == i){
                    sol.push_back(ans);
                    ans.clear();
                }
                if(groupSizes[j]==i){
                    ans.push_back(j);
                }
            }
            if(ans.size()) sol.push_back(ans);
        }
        return sol;
    }
};