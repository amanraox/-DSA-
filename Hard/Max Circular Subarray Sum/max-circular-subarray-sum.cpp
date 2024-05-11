//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
int circularSubarraySum(int arr[], int num){
        
        // your code here
        int arrsum=0,csum=0,max=arr[0];
        bool ispositive=false;
        for(int i=0;i<num;i++)
        {
            arrsum+=arr[i];
            if(arr[i]>0)
            ispositive=true;
            if(arr[i]>max)
            max=arr[i];
        }
        if(arrsum>max)
        max=arrsum;
        if(!ispositive)
        return max;
        int sum=0;
        for(int i=0;i<num;i++)
        {
            if(arr[i]>=0)
            sum+=arr[i];
            else
            {
                csum+=sum;
                if(csum>max)
                max=csum;
                csum+=arr[i];
                if(csum<0)
                csum=0;
                sum=0;
            }
        if(i==num-1)
        {
            csum+=sum;
            if(csum>max)
            max=csum;
        }
        }
        sum=0,csum=0;int min=arr[0];
        for(int i=0;i<num;i++)
        {
            if(arr[i]<0)
            sum+=arr[i];
            else
            {
                csum+=sum;
                if(csum<min)
                min=csum;
                csum+=arr[i];
                if(csum>0)
                csum=0;
                sum=0;
            }
            if(i==num-1)
            {
                csum+=sum;
                if(csum<min)
                min=csum;
            }
        }
        if(arrsum-min>max)max=arrsum-min;
        return max;        
        // your code here
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends