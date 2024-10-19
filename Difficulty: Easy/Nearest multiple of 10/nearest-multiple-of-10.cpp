//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
string roundToNearest(string str) {
       int n = str.size() - 1;
    
    // If the last digit is <= 5, round down by setting the last digit to '0'
    if (str[n] <= '5') {
        str[n] = '0';
        return str;
    }
    
    // If the last digit is > 5, round up
    str[n] = '0';
    n--;
    
    // Loop to handle carry over and replace '9's with '0's if needed
    while (n >= 0 && str[n] >= '0' && str[n] <= '9') {
        if (str[n] == '9') {
            str[n] = '0';
            n--;
        } else {
            str[n]++;
            return str;
        }
    }
    
    // If all digits were '9', prepend '1' to the string
    if (n == -1) {
        return '1' + str;
    }
    
    return str;        // Complete the function
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends