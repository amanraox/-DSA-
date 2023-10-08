class Solution {
public:
    int solve(int i, int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp)
    {
        if(i == nums1.size() || j == nums2.size())
        {
            return 0 ;
        }
        if(dp[i][j] != -1)
          return dp[i][j] ;

       return dp[i][j] = max(max((nums1[i]*nums2[j] + solve(i+1,j+1,nums1,nums2,dp)),solve(i,j+1,nums1,nums2,dp)),
       solve(i+1,j,nums1,nums2,dp)) ;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
       int n = nums1.size() ;
       int m = nums2.size() ;

       vector<vector<int>> dp(501,vector<int> (501,-1)) ;
       int ans = solve(0,0,nums1,nums2,dp) ;  
       
       if(ans == 0)
       {
           sort(nums1.begin(),nums1.end()) ;
           sort(nums2.begin(),nums2.end()) ;

           if(nums1[0] < 0)
              return nums1[n-1]*nums2[0] ;
           else
              return nums1[0]*nums2[m-1] ;
       }

       return ans ;
    }
};