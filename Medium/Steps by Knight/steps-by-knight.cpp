//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    // try bfs
	    queue<pair<int,int > >q;
	    if(KnightPos[0] == TargetPos[0] and KnightPos[1] == TargetPos[1]) return 0;
	    q.push({KnightPos[0]-1 ,KnightPos[1]-1 });
	    
	    int steps = 0;
	    vector<vector<int> > vis(N+1,vector<int>(N+1,0));
	    int d_row = TargetPos[0]-1;
	    int d_col = TargetPos[1]-1;
	    vis[KnightPos[0]-1][KnightPos[1]-1] =1;
	     int delrow[]={-2,-2,-1,-1,1,1,2,2};
        int delcol[]={-1,1,-2,2,-2,2,1,-1};
	    while(!q.empty()){
	        steps++;
	        int n= q.size();
	       
	        
	        // push all possible directions
	        for(int i=0;i<n;i++){
	            auto it = q.front();q.pop();
	            int row = it.first;
	            int col = it.second;
	            
	           for(int j=0;j<8;j++){
	               int nrow = row+delrow[j];
	               int ncol = col+delcol[j];
	               if(nrow == d_row and ncol==d_col) return steps;
	               if(nrow >=0 and nrow <N and ncol >=0 and ncol <N and !vis[nrow][ncol]){
	                   vis[nrow][ncol]=1;
	                   q.push({nrow,ncol});
	               }
	           }
	            
	        }
	    }
	    return -1;
	    // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends