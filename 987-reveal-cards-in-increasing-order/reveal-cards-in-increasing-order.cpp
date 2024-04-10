class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> sorted_copy = deck;
        sort(sorted_copy.begin(), sorted_copy.end());

        int n = deck.size();
        vector<int> ans(n);
        vector<bool> already_inserted(n, false);
        bool should_insert = true;
        int j = 0;
        for(int i = 0; j < n; i++) {
            i %= n;
            if(should_insert & !already_inserted[i]) {
                already_inserted[i] = true;
                ans[i] = sorted_copy[j++];
                should_insert ^= 1;
            } else if(!already_inserted[i]) {
                should_insert ^= 1;
            }
        }
        return ans;
    }
};