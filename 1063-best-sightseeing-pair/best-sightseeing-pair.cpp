class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max = 0, score = values[0];
    for (int i = 1; i < values.size(); ++i) {--score;
      if (score + values[i] > max) max = score + values[i];
      if (values[i] > score) score = values[i];
    }
    return max;
    }
};