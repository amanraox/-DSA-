class Solution {
public:
pair<int,string> solve(string s,string target,int c){
        stack<char> st;
        int ans=0;
        for(auto it:s){
            if(!st.empty() && st.top()==target[0] && it==target[1]){
                ans+=c;
                st.pop();
            }
            else st.push(it);
        }
        string temp="";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return {ans,temp};
    }
    int maximumGain(string s, int x, int y) {
        string ab="abaa",ba="ba";
        if(x<y){
            swap(x,y);
            swap(ab,ba);
        }
        auto it1= solve(s,ab,x);
        auto it2=solve(it1.second,ba,y);
        return it1.first+it2.first;        
    }
};