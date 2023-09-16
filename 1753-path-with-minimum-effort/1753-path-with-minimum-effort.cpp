class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    bool isSafe(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    
    int minimumEffortPath(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});
        ans[0][0] = 0;
        
        while (!pq.empty()) {
            int diff = pq.top().first;
            auto cor = pq.top().second;
            int x = cor.first;
            int y = cor.second;
            pq.pop();
            
            
            
            for (auto& dir : dirs) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                if (isSafe(x_, y_, n, m)) {
                    int adiff = abs(v[x][y] - v[x_][y_]);
                    int mdiff = max(adiff, diff);
                    if (ans[x_][y_] > mdiff) {
                        ans[x_][y_] = mdiff;
                        pq.push({mdiff, {x_, y_}});
                    }
                }
            }
        }
        
        return ans[n - 1][m - 1];
        
    }
};