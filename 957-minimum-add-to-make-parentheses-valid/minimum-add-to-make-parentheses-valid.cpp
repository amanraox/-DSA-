class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.length(),op=0,cl=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')++op;
            else ++cl;
            if(cl>op)++ans,++op;
        }
        if(op>cl)ans+=(op-cl);
        return ans;
    }
};