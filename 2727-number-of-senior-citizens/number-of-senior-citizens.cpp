class Solution {
public:
    int countSeniors(vector<string>& d) {
        int ans=0;
        for(int i=0;i<d.size();i++)
            if(((d[i][11]-'0')*10+(d[i][12]-'0'))>60)++ans;
        return ans;
    }
};