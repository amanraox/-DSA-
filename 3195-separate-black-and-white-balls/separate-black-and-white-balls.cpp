class Solution {
public:
    long long minimumSteps(string s) {
        long long k = 0,b = 0; 
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '0') k+=b; 
            else b++;
        return k;
    }
};