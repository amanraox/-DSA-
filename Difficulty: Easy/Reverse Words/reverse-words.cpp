//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        int n=0,a=0;
        for(auto &x:str)  if(x=='.') n++;
        vector<string >arr(n+2);
        for(auto &x:str){
            if(x!='.'){
                arr[a]+=x;
                //cout<<arr[a]<<endl;
            }
            else{
                a++;
               // cout<<arr[a]<<endl;
            }
        }
        string ans;
        for(int i=n+1;i>=0;i--)
        {  
            ans+=arr[i]; 
          //  cout<<ans<<endl;
            if(i!=0) 
            ans+='.';
            
        }
        return ans=ans.substr(1,str.size());
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends