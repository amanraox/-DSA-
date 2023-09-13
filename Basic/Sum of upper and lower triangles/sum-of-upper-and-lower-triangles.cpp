//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        // code here
        long long sum=0;//sum1=sum2=0;
        for(int i=0;i<n;i++)//upper triangle
        {
            for(int j=i;j<n;j++)
            {
                sum +=matrix[i][j];
            }
        }
        vector<int> ans;
        ans.push_back(sum);
        sum=0;
        for(int i=0;i<n;i++)//lower triangle
        {
            for(int j=0;j<=i;j++)
            {
                sum +=matrix[i][j];
            }
        }
        ans.push_back(sum);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        vector<int> result = ob.sumTriangles(matrix,n);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends