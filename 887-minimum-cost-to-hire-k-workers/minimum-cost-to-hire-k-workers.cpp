class Solution {
public:
class Compare {
    public:
        bool operator()(const vector<int> &a, const vector<int> &b) {
            // Use double division to ensure accurate ratios.
            return (static_cast<double>(a[1]) / a[0]) < (static_cast<double>(b[1]) / b[0]);
        }
    };

    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<vector<int>> workers(n);

        for (int i = 0; i < n; i++) {
            workers[i] = {quality[i], wage[i]};
        }

        // Sort workers by their wage-to-quality ratio.
        sort(workers.begin(), workers.end(), Compare());

        double ans = numeric_limits<double>::max();
        int sum = 0;
        priority_queue<int> maxQualities;

        for (int i = 0; i < n; i++) {
            sum += workers[i][0];
            maxQualities.push(workers[i][0]);

            if (maxQualities.size() > k) {
                sum -= maxQualities.top();
                maxQualities.pop();
            }

            if (maxQualities.size() == k) {
                ans = min(ans, static_cast<double>(workers[i][1]) * sum / workers[i][0]);
            }
        }

        return ans;        
    }
};