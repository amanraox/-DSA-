class Solution {
public:
    int prefixCount(vector<string>& w, string p) {
        int ans=0;
        for(int i=0;i<w.size();i++)
        {
            int j=0;
            for(;j<p.length();j++)
            {
                if(p[j]!=w[i][j])break;
            }
            if(j==p.length())++ans;
        }
        return ans;
    }
};