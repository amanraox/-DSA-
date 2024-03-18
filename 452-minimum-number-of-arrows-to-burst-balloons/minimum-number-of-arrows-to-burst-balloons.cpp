class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(begin(p) , end(p));

        int ind = 1;
        int min_range = p[0][0];
        int max_range = p[0][1];
        int ar = 1;
        int n = p.size();

        while(ind < n){
            if(p[ind][0] <= max_range){
                min_range = max(min_range , p[ind][0]);
                max_range = min(max_range , p[ind][1]);
                ind++;
            }
            else{
                ar++;
                min_range = p[ind][0];
                max_range = p[ind][1];
                ind++;
            }
        }
        return ar;
    }
};