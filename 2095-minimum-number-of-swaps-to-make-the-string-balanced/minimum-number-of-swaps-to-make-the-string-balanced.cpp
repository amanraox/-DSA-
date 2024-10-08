class Solution {
public:
    int minSwaps(string s) {
        int ck = 0, ever = 0;
        int mxn = 0;
        for(int i=0;i<s.length();i++) {
            ck += (s[i] == '[' ? 1 : -1);
            mxn = fmin(ck, mxn);
        }
        return (-mxn + 1) >> 1;
    }
};