//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

bool possible(int arr[], int n, int k, long long mid){
    int painter = 1;
    long long board = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > mid) return false;  // Single board larger than mid, impossible to paint
        if(board + arr[i] > mid){
            painter++;  // Need an additional painter
            if(painter > k) return false;  // Exceeded number of painters available
            board = arr[i];  // Start new painter's sum
        } else {
            board += arr[i];  // Add to current painter's sum
        }
    }
    return true;
}

class Solution {
public:
    long long minTime(int arr[], int n, int k) {
        long long s = *max_element(arr, arr + n);  // Start from the largest single board
        long long sum = accumulate(arr, arr + n, 0LL);  // Use long long to prevent overflow
        long long e = sum;
        long long ans = sum;
        
        while(s <= e){
            long long mid = s + (e - s) / 2;
            
            if(possible(arr, n, k, mid)){
                ans = mid;  // Found a valid configuration, try for a smaller max time
                e = mid - 1;
            } else {
                s = mid + 1;  // Need a larger max time
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends