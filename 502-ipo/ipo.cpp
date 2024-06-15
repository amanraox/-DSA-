class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        priority_queue<int> maxHeap;
        for (int i = 0; i < profits.size(); i++) {
            minHeap.push({capital[i], profits[i]});
        }
        for (int i = 0; i < k; i++) {
            while (!minHeap.empty() && minHeap.top().first <= w) {
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }
            if (maxHeap.empty()) break;
            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};