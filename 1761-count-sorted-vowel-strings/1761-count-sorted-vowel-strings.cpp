class Solution {
public:
    int countVowelStrings(int n) {
        return (n+4)*(n+3)*(n+1)*(n+2)/24;
    }
};