//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {
vector<int> diff(maxx + 2, 0);
    
    for (int i = 0; i < n; i++) {
        diff[l[i]]++;           
        diff[r[i] + 1]--;   
    }
    
    int maxOccur = 0;  
    int result = 0;   
    int currSum = 0;  
    
    for (int i = 0; i <= maxx; i++) {
        currSum += diff[i]; 
        
        if (currSum > maxOccur) {
            maxOccur = currSum;  
            result = i;          
        }
    }
    
    return result;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    // taking testcases
    cin >> t;

    while (t--) {
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++) {

            cin >> r[i];
            if (r[i] > maxx) {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}
// } Driver Code Ends