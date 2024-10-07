class Solution {
public:
    int minLength(string s) {
        int n=s.length(),ans=0;
        vector<int> a;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='A') {a.push_back(1);continue;}
            else if(s[i]=='C'){a.push_back(2);continue;}
            if(a.size()){
                if(s[i]=='B' and a.back()==1)a.pop_back(),ans++;
                else if(s[i]=='D' and a.back()==2)a.pop_back(),ans++;
                else a.clear();}
        }
        return n-2*ans;
    }
};