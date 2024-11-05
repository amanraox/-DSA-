//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        if(arr.size() == 3){
            if(arr[0] + arr[1] == arr[2]){
                return true;
            }
        }
        set<int >st;
        for(auto it: arr){
            st.insert(it);
        }
       for(int i = 0; i < arr.size() - 1; i++){
           for(int j = i+1; j < arr.size(); j++ ){
               if(st.find(arr[i] + arr[j] ) != st.end()){
                   return true;
               }
           }
       }
       return false;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends