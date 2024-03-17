class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;

        int cur = 0;
        while (cur < n && intervals[cur][1] < newInterval[0]) {
            res.push_back(intervals[cur]);
            cur++;
        }

        if (cur == n) {
            res.push_back(newInterval);
            return res;
        }
        
        if (intervals[cur][0] > newInterval[1]) 
            res.push_back(newInterval);
        else {
            int l = min(intervals[cur][0], newInterval[0]);
            int r = max(intervals[cur][1], newInterval[1]);

            cur++;
            while (cur < n && intervals[cur][0] <= r)
                r = max(r, intervals[cur++][1]);
                
            res.push_back({l, r});
        }
                          
        while (cur < n)
            res.push_back(intervals[cur++]);
        return res;
    }
};