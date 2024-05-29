//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
//User function template in C++


class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {sort(A1.begin(),A1.end()); // sort A1
        set<int> s(A2.begin(),A2.end()); //remove dups from A2
        map<int,int> m; // to store element and its frequency in A1
        for(int i=0;i<A1.size();i++){
            m[A1[i]]++;
        }
        vector<int> arr;
        for(int i=0;i<A2.size();i++){
            if(m.find(A2[i])!=m.end()){
                for(int j=0;j<m[A2[i]];j++){
                    arr.push_back(A2[i]);
                }
                m.erase(A2[i]);
            }
        }
        for(auto pos=m.begin();pos!=m.end();pos++){
            for(int i=0;i<pos->second;i++)
                arr.push_back(pos->first);
        }
        return arr;
        //Your code here
    } 
};

//{ Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 

// } Driver Code Ends