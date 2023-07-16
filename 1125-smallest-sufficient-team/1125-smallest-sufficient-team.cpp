class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> mp;
        int n = req_skills.size();
        int m = people.size();
        vector<vector<int> > dp(1<<n, vector<int>(1000));
        int skill[m];
        fill(skill, skill + m, 0);
        dp[0].clear();
        for(int i=0;i<n;i++)
            mp[req_skills[i]]=i;
        for(int i=0;i<m;i++){
            for(auto x: people[i]){
                skill[i] |= 1<<mp[x];
            }
        }
        for(int i=1;i<1<<n;i++){
            for(int j=0;j<m;j++){
                if((skill[j]&i) != skill[j])continue;
                int mask = skill[j];                
                for(int sub = mask; sub>0; sub = (sub-1)&mask){
                    
                    int temp = i&(~sub);
                     if(dp[i].size() > dp[temp].size() + 1){
                        dp[i] = dp[temp];
                        dp[i].push_back(j);
                     }
                }
                
            }
        
        }
    
        
        
        return dp[(1<<n)-1]; 
    }
};