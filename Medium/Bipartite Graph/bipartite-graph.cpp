//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
bool dfs(vector<int> g[], vector<int> &vis, int i, int color)
    {
        vis[i]=color;
        for(auto j:g[i])
        {
            if(vis[j]==-1)
            {
                if(dfs(g,vis,j,!color)==false)
                   return false;
            }
            else if(vis[j]==color)
              return false;
        }
        
        return true;
    }
public:
    
	bool isBipartite(int n, vector<int>graph[]){
	    // Code here
	    vector<int> vis(n,-1);
	    
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                if(dfs(graph,vis,i,0)==false)
                  return false;
            }
        }
        
        return true;

	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends