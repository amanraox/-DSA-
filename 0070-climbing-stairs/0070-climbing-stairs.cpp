class Solution {
public:
    int climbStairs(int n) {
        int s=0,e=1,c;
        while(n--)
        {
            c=s+e;
            s=e;
            e=c;
        }
        return c;
    }
};