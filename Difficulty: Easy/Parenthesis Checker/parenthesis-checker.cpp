//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        int n=x.size();
        stack<char>st;
        
        for(char ch:x){
            
            // if st is not empty then only check for st.top
            // given are the different bracket's conditions for popping out of the stack
            if(!st.empty() && ( (st.top()=='(' && ch==')') 
            || (st.top()=='{' && ch=='}') 
            || (st.top()=='[' && ch==']')
            ) )  st.pop();
            
            // if the stack is empty or any other case occurs, just push the char
            else st.push(ch);
        }
        
        // check whether the stack is empty of not
        return st.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends