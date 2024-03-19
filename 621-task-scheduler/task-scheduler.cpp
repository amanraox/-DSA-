class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(auto i:tasks) {
            freq[i-'A']++;
        }
        sort(freq.rbegin(),freq.rend());
        int emptyBlocks=(freq[0]-1)*n;
        for(int i=1;i<26;i++) {
            if(freq[i]==0) {
                break;
            }
            emptyBlocks -= min(freq[i],freq[0]-1);
        }
        if(emptyBlocks>0) {
            return tasks.size()+emptyBlocks;
        }
        else {
            return tasks.size();
            }
    }
};