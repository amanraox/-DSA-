//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        vector<int> sol;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> pq;
        int ca = N - 1, cb = N - 1;
        int csum = A[ca] + B[cb];
        pq.push({csum, {ca, cb}});
       
        set<pair<int, int>> visited;
        
        visited.insert({ca, cb});
        while(K > 0 && !pq.empty()) {
            pair<int, pair<int, int>> top = pq.top();
            pq.pop();
            int csum = top.first, ca = top.second.first, cb = top.second.second;
            sol.push_back(csum);
            K--;
            int nca = ca - 1, ncb = cb - 1;
            if(ncb >= 0 && visited.find({ca, ncb}) == visited.end()) {
                visited.insert({ca, ncb});
                pq.push({A[ca] + B[ncb], {ca, ncb}});
            }
            if(nca >= 0 && visited.find({nca, cb}) == visited.end()) {
                visited.insert({nca, cb});
                pq.push({A[nca] + B[cb], {nca, cb}});
            }
        }
        return sol;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends