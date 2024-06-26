class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]] = i;
        }
        vector<char> vis(26,0);
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char x = s[i];
            if(vis[x-'a'] == 1)
                continue;
            while(!st.empty() && st.top()>x && mp[st.top()]>i){
                vis[st.top()-'a'] = 0;
                st.pop();
            }
            vis[x-'a'] = 1;
            st.push(x);
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};