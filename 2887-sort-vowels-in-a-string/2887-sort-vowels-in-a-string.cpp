class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        string t = s;
        
        string x;
        vector<int> idx; // store indexes of vowels
        for(int i=0 ; i<n ; i++) {
            if(isVowel(s[i])) {
                idx.push_back(i);
                x += s[i];
            }
            else {
                t[i] = s[i];
            }
        }
        
        sort(begin(x),end(x));
        int i = 0;
        for(auto m:idx) {
            t[m] = x[i++];
        }
        return t;
    }
    
    bool isVowel(char c) {
        if(c=='a' ||  c=='e' || c=='i' || c=='o' || c=='u' || c=='A' ||  c=='E' || c=='I' || c=='O' || c=='U') return true;
        return false;   
    }
};