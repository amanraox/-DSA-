//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n=arr.size();
        int c=0;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
          mp[arr[i]]++;
        }
        for(auto i:mp)
        {
            
            if(mp.find((target)-(i.first))!=mp.end())
            {
                if(i.first==(target)-(i.first))
                  c+=(i.second*(i.second-1))/2;
                else if(i.first<((target)-(i.first)))
                   c+=(mp[target-i.first]*i.second);
            }
        }
        return c;
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends