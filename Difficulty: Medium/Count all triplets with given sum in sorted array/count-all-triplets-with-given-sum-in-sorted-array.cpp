//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int ans=0;
        for(int i=0;i<arr.size()-2;i++){
            
            int j=i+1;
            int k=arr.size()-1;
            while(j<k){
                if(arr[i]+arr[j]+arr[k]>target) k--;
                else if(arr[i]+arr[j]+arr[k]<target) j++;
                else {
                    int temp=arr[j],temp2=arr[k];
                    int count=0,count1=0;
                    while(arr[j]==temp && j<k){j++; count++;}
                    
                    j--;
                    while(arr[k]==temp2 && k>j){k--; count1++;}
                     
                     j++;
                    if(temp==temp2) ans+=(count*(count+1))/2;
                    else ans+=count*count1;
                }
            }
        
        }
        return ans;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends