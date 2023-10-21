class Solution {
public:
    int reverse(int x) {
        long long ans=0;
        bool neg=0;
        if(x<0)neg=1;
        int y=abs(x),i=0;
        while(y>0)
        {
            int e=y%10;
            ans=ans*10+e;
            y/=10;
        }
        if(ans>=(-2147483648) and ans<=2147483647)
        {
            if(neg)
        return -ans;
        return ans;
        }
        return 0;
        
    }
};