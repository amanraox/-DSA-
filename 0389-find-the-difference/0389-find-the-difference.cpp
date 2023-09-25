class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>v(26,0);

        for(int i=0;i<t.length();i++){
            v[t[i]-'a']++;
        }

        for(int i=0;i<s.length();i++){
            v[s[i]-'a']--;
        }

        for(int i=0;i<v.size();i++){
            if(v[i]==1)return i+'a';
        }
        return 0;
    }
};