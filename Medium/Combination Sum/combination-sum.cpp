//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
void find_combinations(vector<int>& arr, int target, int start, 
        vector<int>& current, vector<vector<int> >& result) {
            
        if (target < 0) {
            return;
        }
        
        if (target == 0) {
            result.push_back(current);
            return;
        }
    
        for (int i = start; i < arr.size(); ++i) {
            // Skip duplicates to avoid repeated combinations
            if (i > start && arr[i] == arr[i - 1]) {
                continue;
            }
            current.push_back(arr[i]);
            
            find_combinations(arr, target - arr[i], i, current, result);
            
            current.pop_back();
        }
    }

    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<vector<int> > result;
        vector<int> current;
        
        sort(A.begin(), A.end());
        
        find_combinations(A, B, 0, current, result);
        
        return result;
        // Your code here
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends