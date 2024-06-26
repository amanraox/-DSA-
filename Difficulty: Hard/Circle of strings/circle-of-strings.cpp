//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#include <vector>
#include <unordered_map>
#include <list>
#include <string>

class Solution {
    void dfs(int node, std::unordered_map<int, bool>& visit, std::unordered_map<int, std::list<int>>& adjList) {
        visit[node] = true;
        for (auto it : adjList[node]) {
            if (!visit[it]) dfs(it, visit, adjList);
        }
    }
    
public:
    int isCircle(int N, std::vector<std::string> A) {
        std::vector<int> indeg(26, 0), outdeg(26, 0);
        std::unordered_map<int, std::list<int>> adjList;
        
        for (int i = 0; i < N; i++) {
            std::string str = A[i];
            int u = str[0] - 'a';
            int v = str[str.size() - 1] - 'a';
            adjList[u].push_back(v);
            outdeg[u]++;
            indeg[v]++;
        }
        
        // Check if in-degree and out-degree of every character match
        for (int i = 0; i < 26; i++) {
            if (indeg[i] != outdeg[i]) return 0;
        }
        
        // Check if all characters are part of a single strongly connected component
        std::unordered_map<int, bool> visit;
        int start = A[0][0] - 'a';
        
        dfs(start, visit, adjList);
        
        for (int i = 0; i < 26; i++) {
            if (indeg[i] > 0 && !visit[i]) return 0;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends