class Solution {
public:
    int minLength(string s) {
        int ans=0;vector<int> a;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='A'){a.push_back(1);continue;}
            else if(s[i]=='C'){a.push_back(2);continue;}
            else if(a.size() and s[i]=='B' and a.back()==1)a.pop_back(),ans++;
            else if(a.size() and s[i]=='D' and a.back()==2)a.pop_back(),ans++;
            else a.clear();
        }
        return s.length()-2*ans;
    }
};