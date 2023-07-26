//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    void heapify(int arr[], int n, int i)  
    {
      int mini=i;
      int l=(i*2+1);
      int r=(i*2+2);
      
      if(l<n && arr[l]>arr[mini]) mini=l;
      
      if(r<n && arr[r]>arr[mini]) mini=r;
      
      if(mini!=i){
          swap(arr[i],arr[mini]);
          heapify(arr,n,mini);
      }
      
    }
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
        for(int i=(n-1)/2;i>=0;i--){
            heapify(arr,n,i);
        }
    }
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        for(int i=n-1;i>=0;i--){
            swap(arr[i],arr[0]);
            heapify(arr,i,0);
        }
        
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends