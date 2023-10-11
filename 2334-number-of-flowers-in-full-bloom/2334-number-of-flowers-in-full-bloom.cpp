class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int>start,end;
        for (auto it: flowers)
        {
            start.push_back(it[0]);
            end.push_back(it[0+1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        vector<int>ans;
        for (int i=0;i<people.size();i++)
        {
            int s=upper_bound(start.begin(),start.end(),people[i])-start.begin();
            int e=lower_bound(end.begin(),end.end(),people[i])-end.begin();
            ans.push_back(s-e);
        }
        return ans;
    }
};