//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
void dfs(unordered_map<int,vector<int>>&adj,unordered_map<int,bool>&visited,int node){
        //component.push_back(node);
        visited[node] = 1;
        for(auto i: adj[node]){
            if(!visited[i]){
                dfs(adj,visited,i);
            }
        }
    }
    int numProvinces(vector<vector<int>> isConnected, int V) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,bool>visited;
        int n = isConnected.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int cnt = 0;
        for(int i = 1;i<=n;i++){
            if(!visited[i]){
                
                dfs(adj,visited,i);
                cnt++;
            }
        }
        return cnt;        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends