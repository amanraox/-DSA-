//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dp[100001][2];
    int solve(vector<int> &prices,int i,bool buy){
        
        if(i >= prices.size())
            return 0 ;
            
        if(dp[i][buy] != -1)
            return  dp[i][buy] ;
        
        int ans = -1 ;
        if(buy){
            int buyToday = -prices[i] + solve(prices,i+1,0);
            int buyLater = solve(prices,i+1,1);
            
            ans = max(buyToday,buyLater);
        }
        
        else{
            int sellToday = prices[i] + solve(prices,i+1,1);
            int sellLater = solve(prices,i+1,0);
            
            ans = max(sellToday,sellLater);
        }
        
        return dp[i][buy] =  ans ;
    }
  
  
    int maximumProfit(vector<int> &prices) {
        
        memset(dp,-1,sizeof(dp));
        int ans = solve(prices,0,1);
        return ans ;
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends