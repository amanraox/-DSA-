class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> pew;
        int temp = 0;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                pew.push_back(asteroids[i]);
            } else {
                while (!pew.empty() && pew.back() > 0 && pew.back() < abs(asteroids[i])) {
                    pew.pop_back();
                }
                if (!pew.empty() && pew.back() > 0 && pew.back() == abs(asteroids[i])) {
                    pew.pop_back();
                } else if (pew.empty() || pew.back() < 0) {
                    pew.push_back(asteroids[i]);
                }
            }
        }
        return pew; 
    }
};