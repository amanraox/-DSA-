//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string num1, string num2) {
        // Your code goes here
        string sum;
        int i = num1.size() - 1, j = num2.size() - 1;
        int add = 0, digit;
        
        while(i >= 0 || j >= 0) {
            int add1 = 0, add2 = 0;
            if(i >= 0)
                add1 = num1[i--] - '0';
            if(j >= 0)
                add2 = num2[j--] - '0';
                
            add = add1 + add2 + (add / 10);
            sum.push_back((add % 10) + '0');
        }
        
        if((add / 10) != 0)
            sum.push_back(((add / 10) % 10) + '0');
            
        while(sum[sum.size()-1] == '0' && sum.size() > 1)
            sum.pop_back();
            
        reverse(sum.begin(), sum.end());
        
        return sum;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends