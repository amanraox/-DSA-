class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long maxi=0;
        
        vector<long long> degree(n,0);
        for(auto it: roads){
            degree[it[0]]++;
            degree[it[1]]++;
        }
        sort(degree.begin(),degree.end(),greater<int>());

        int i=0;
        int val=n; 
        while(i<n && degree[i]>0){
            maxi += val*(degree[i]);
            i++;val--;
        }
        return maxi;
    }
};