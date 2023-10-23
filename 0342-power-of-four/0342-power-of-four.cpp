class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)return true;
        if(n%4!=0)return false;
        while(n>15)
        {
            n/=4;
            if(n%4!=0)return false;
        }
        if(n==4)return true;
        return false;
    }
};