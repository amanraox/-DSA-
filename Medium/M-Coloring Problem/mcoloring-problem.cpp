//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
bool color(bool graph[101][101],vector<int>&vis, int it,int col,int n){
          for(int i = 0 ; i < n ; i++){
            if(graph[it][i] && vis[i] == col) return 0 ;
        }
        return 1 ;
    }
    bool ispos(int ver,bool graph[101][101],  vector<int>&vis,int m, int n){
        if(ver==n)
        return true;
        for(int i=1; i<=m; i++){
            if(color(graph,vis,ver,i,n)){
                vis[ver]=i;
                if(ispos(ver+1,graph,vis,m,n))
                  return true;
               
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
      
        vector<int>vis(n,0);
        if(ispos(0,graph,vis,m,n))
        return true;
        return false;        // your code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends