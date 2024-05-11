//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
string findOrder(string dict[], int N, int K) {
        vector<vector<int>> graph(K);
        int n=N;
        for(int i=0;i<n-1;i++){
            int y=dict[i].size(),z=dict[i+1].size();
            for(int j=0;j<min(y,z);j++){
                if(dict[i][j]!=dict[i+1][j]){
                    int ew=dict[i][j]-'a';
                    int ew1=dict[i+1][j]-'a';
                    graph[ew].push_back(ew1);
                    break;
                }
            }
        }
        
    vector<int> indegree(K);
    string ans="";
    queue<int> hello;
    for(int i=0;i<K;i++){
        for(int j=0;j<graph[i].size();j++)
            {indegree[graph[i][j]]++;}
        }
        
    for(int i=0;i<K;i++){if(indegree[i]==0){hello.push(i);}}
    
     while(!hello.empty()){
            int front=hello.front();hello.pop();
            char ch = 'a' + front;ans.push_back(ch);
            for(int k=0;k<graph[front].size();k++){
                indegree[graph[front][k]]--;
                if(indegree[graph[front][k]]==0){
                    hello.push(graph[front][k]);
                }
            }
        }
    return ans;        //code here
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends