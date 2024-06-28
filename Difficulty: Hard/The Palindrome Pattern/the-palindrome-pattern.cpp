//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &mat) {
int rows = mat.size();
        int col = mat[0].size();
        for(int i = 0; i < rows; i++){
            int flag = 0;
            for(int j = 0; j < col/2; j++){
                if(mat[i][j] != mat[i][col - j - 1]){ 
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) return to_string(i) + " R";
        }
        
        for(int i = 0; i < col; i++){
            int flag = 0;
            for(int j = 0; j < rows/2; j++){
                if(mat[j][i] != mat[rows - j - 1][i]){ 
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) return to_string(i) + " C";
        }
        return "-1";    
        
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends