class Solution {
public:
    int climbStairs(int n) {
        int s=0,e=1;
        while(n--)
        {
            s=s^e,e=s^e,s=s^e,e+=s;
        }
        return e;
    }
};