//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        int bitCount = 0;
        
        for (int i = 0; (1 << i) <= n; i++) {
            // Number of sets of 2^i in all numbers from 1 to N
            int sets = (n + 1) / (1 << (i + 1));
            // Number of bits set in all sets of 2^i
            bitCount += sets * (1 << i);
            // Extra bits, if any
            bitCount += max(0, (n + 1) % (1 << (i + 1)) - (1 << i));
        }
        return bitCount;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends