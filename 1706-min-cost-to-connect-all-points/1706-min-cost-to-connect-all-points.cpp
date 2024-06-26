class Solution {
public:
    int dist(int x1, int y1, int x2, int y2){
        return abs (x1-x2) + abs(y1-y2);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() < 1) return 0;

        int V = points.size();
        int result = 0;
        
        vector<int> minDists(V, INT_MAX);
        vector<int> mst(V, 0);
        
        minDists[0] = 0;
        mst[0] = 1;
        for (auto i = 0 ; i < V; i++) {
            minDists[i] = dist(points[0][0],points[0][1],points[i][0],points[i][1]);
        }
        for(int i = 0;i<V;i++){
            int mini = INT_MAX;
            int index = 1;
            for(int j =1;j<V;j++){
                if(!mst[j] && minDists[j] < mini){
                    mini = minDists[j];
                    index = j;
                }
            }
            if(mini == INT_MAX)break;
            result +=mini;
            mst[index] = 1;
            for(int j = 1;j<V;j++){
                if(mst[j])continue;
                int d = dist(points[index][0],points[index][1],points[j][0],points[j][1]);
                if(d < minDists[j]){
                    minDists[j] = d;
                }
            }
        }


        return result;
    }
};