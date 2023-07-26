class Solution {
public:
   bool good(vector<int>& dist, double hr, int h) {
        double cnt = 0;
        for(int i = 0; i < dist.size(); i++)
            if(i == dist.size() - 1) cnt += (double) dist[i] / h;
            else cnt += ((dist[i] + h - 1) / h);
        return cnt <= hr;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour <= n - 1) return -1;
        int lo = 1, hi = 1e9;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if(good(dist, hour, mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};