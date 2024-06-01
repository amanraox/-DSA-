//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        int INF = 1e8;
        vector<int> res(V, INF);
        res[S] = 0;
        bool change = false;
        for (int i = 0; i < V; i++) {
            change = false;
            for (int e = 0; e < edges.size(); e++) {
                if (res[edges[e][0]] == INF) {
                    continue;
                } else if (res[edges[e][1]] == INF || res[edges[e][0]] + edges[e][2] < res[edges[e][1]]) {
                    res[edges[e][1]] = res[edges[e][0]] + edges[e][2];
                    change = true;
                }
            }
        }
        if (change) {
            return vector<int>(1, -1);
        }
        return res;        // Code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends