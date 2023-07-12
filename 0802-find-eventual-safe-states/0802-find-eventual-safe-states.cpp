#define maxn 10005
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(auto j: graph[i])
            {
                adj[j].push_back(i);
            }
        }
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto j:adj[i])
                indegree[j]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(q.empty()==false)
        {
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(int u:adj[curr])
            {
                indegree[u]--;
                if(indegree[u]==0)
                    q.push(u);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};