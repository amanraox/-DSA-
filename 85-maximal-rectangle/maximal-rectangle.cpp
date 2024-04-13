class Solution {
public:
int maxInHistogram(vector<int>& arr) {
        int n=arr.size();
        int maxi=0;
        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || arr[st.top()]>=arr[i])){
                int height=arr[st.top()];
                st.pop();
                int width;
                if(st.empty())  width=i;
                else     width=i-st.top()-1;
                maxi=max(maxi,(height*width));
            }
            st.push(i);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        int maxi=0;
        vector<int> histo(c,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]=='1')    histo[j]+=1;
                else    histo[j]=0;
            }
            maxi=max(maxi,maxInHistogram(histo));
        }
        return maxi;        
    }
};