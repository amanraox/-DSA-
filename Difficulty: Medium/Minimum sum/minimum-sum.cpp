//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

string Add (string num1, string num2){
    if (num1 == "") return "";
    else if (num2 == "") return num1;
    int i = num1.size(), j = num2.size(), carry{0};
    stack <int> hash;
    while (i > 0 && j > 0){
        int digit1 = num1[--i] - '0', digit2 = num2[--j] - '0';
        int sum = digit1 + digit2 + carry; 
        hash.push(sum % 10);
        carry = sum/10;
    }
    while (i > 0){
        int digit1 = num1[--i] - '0';
        int sum = digit1 + carry; 
        hash.push(sum % 10);
        carry = sum/10;
    }
    while (j > 0){
        int digit2 = num2[--j] - '0';
        int sum = digit2 + carry; 
        hash.push(sum % 10);
        carry = sum/10;
    }
    if (carry != 0) hash.push(carry);
    while (hash.top() == 0) hash.pop();
    string result;
    while (!hash.empty()){
        result += hash.top() + '0';
        hash.pop();
    }
    return result;
}
class Solution {
  public:
    string minSum(vector<int> &arr) {
        sort (arr.begin(), arr.end());
        int size = arr.size();
        string num1, num2;
        for (int i = 0; i < size - 1; i += 2){
            num1 += arr[i] + '0';
            num2 += arr[i + 1] + '0';
        }
        if (size % 2 != 0 && num1 > num2) num2 += arr[size - 1] + '0';
        else if (size % 2 != 0) num1 += arr[size - 1] + '0';
        return Add(num1, num2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends