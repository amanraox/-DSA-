//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int s =0;
        int e=arr.size()-1;
        int ans =0;
        while(s<e){
           int sum =arr[s]+arr[e];
           if(sum>target){
               e--;
           }
           else if(sum<target){
               s++;
           }
           else{
               if(arr[s]==arr[e]){
                   int count = e-s+1;
                  ans+=(count*(count-1))/2;
                  break;
               }
               else{
                  
                   int count1=1;
                   int count2=1;
                   
                   while(s+1<e&&arr[s]==arr[s+1]){
                       count1++;
                       s++;
                   }
                   while(e-1>s&&arr[e]==arr[e-1]){
                       count2++;
                       e--;
                   }
                   ans+=(count1*count2);
                 
                   s++;
                   e--;
                   
               }
           }
        }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends