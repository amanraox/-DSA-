//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> res;
    bool isSafe(int row, int col, int n, vector<vector<int>>&ans){
        // int i,j;
        for( int i=0;i<col;i++)
         if(ans[row][i]) return false;
         
        // left upper diagonal 
        for(int i=row,j=col; i>=0 && j>=0 ; i--,j--)
         if(ans[i][j]) return false;
        
        for(int i=row,j=col; i<n && j>=0 ; i++,j--)
         if(ans[i][j]) return false;
         
         return true;
        
    }
    
    bool solveNQUtil(vector<vector<int>> &ans, int col, int n, vector<int>path){
        if(col>=n) { 
            res.push_back(path);
            return true;
        }
        
        for(int i=0; i<n; i++){
            if(isSafe(i,col,n,ans)){
                ans[i][col]=1;
                path[col]=i+1;
                if(solveNQUtil(ans,col+1,n,path)!=true);
                    ans[i][col]=0;
            }
        }
        
        return false;
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>ans(n,vector<int>(n,0));
        vector<int> path(n,0);
        
        solveNQUtil(ans,0,n,path);
        
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends