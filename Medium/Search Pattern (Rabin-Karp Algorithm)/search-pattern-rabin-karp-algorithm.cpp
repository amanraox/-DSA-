//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            int n = text.length(); 
            int m = pattern.length(); 
            vector<int> index_arr; 
             
            for(int i=0; i<n; i++) { 
                 
                string temp = text.substr(i, m); 
                // cout<<"temp: "<<temp<<endl; 
                 
                if(temp == pattern) 
                    index_arr.push_back(i+1); 
            } 
             
            return index_arr; 
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends