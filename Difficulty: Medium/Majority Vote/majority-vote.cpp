//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int n=nums.size();
        if(n<3)
        return nums;
        
        vector<int>ans;
        int a=nums[0],b=nums[1];
        int ac=1,bc=1;
        for(int i=2;i<n;i++){
            if(nums[i] == a){
                ac++;
            }
            else if(nums[i]==b){
                bc++;
            }
            else{
                if(ac>0 && bc>0){
                    ac--;
                    bc--;
                }
                if(ac==0){
                    a=nums[i];
                    ac=1;
                }
                else if(bc==0){
                    b=nums[i];
                    bc=1;
                }
            }
        }
        
        ac=bc=0;
        for(int i=0;i<n;i++){
            if(nums[i]==a){
                ac++;
            }
            else if(nums[i]==b){
                bc++;
            }
        }
        
        if(ac>n/3){
            ans.push_back(a);
        }
        if(bc>n/3){
            ans.push_back(b);
        }
        n=ans.size();
        if(n==0){
            return {-1};
        }
        if(n>1 && ans[0]>ans[1]){
            swap(ans[0],ans[1]);
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

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends