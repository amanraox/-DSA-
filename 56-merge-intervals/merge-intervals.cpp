class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& t) {
        int n=t.size(),k=-1;
        sort(t.begin(),t.end());
        bool b=0;
        if(n==1)return t;
        vector<vector<int>> ans;
        for(int i=0;i<n-1;i++)
        {
            if(t[i][1]>=t[i+1][0])
            {
                
                t[i+1][0]=min(t[i][0],t[i+1][0]);
                t[i+1][1]=max(t[i][1],t[i+1][1]);
                ans.push_back({t[i+1][0],t[i+1][1]});
                b=0;++k;
            }
            else 
            {
                ans.push_back({t[i][0],t[i][1]});
                b=1;++k;
            }
            if(k>0 and ans[k-1][0]>=ans[k][0])
            {
                ans[k-1][0]=min(ans[k][0],ans[k-1][0]);
                ans[k-1][1]=max(ans[k][1],ans[k-1][1]);
                ans.pop_back();--k;
                //ans.push_back({t[i+1][0],t[i+1][1]});
            }
        }
        if(b)
        ans.push_back({t[n-1][0],t[n-1][1]});
        return ans;
    }
};