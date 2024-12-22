//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int X) {
        int N = mat.size();
        int M = mat[0].size();
        for(int i=0;i<N;i++){
            int s = 0;
            int e = M-1;
            int mid = s + (e-s)/2;
            while(s<=e){
                int el = mat[i][mid];
                if(el==X){
                    return 1;
                }
                if(el>X){
                    e = mid-1;
                }
                else{
                    s=mid+1;
                }
                mid = s + (e-s)/2;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends