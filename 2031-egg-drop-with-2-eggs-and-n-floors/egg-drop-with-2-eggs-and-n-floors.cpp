class Solution {
public:
    int twoEggDrop(int n) {
        int k=1;
        if(n==1)return 1;
        while(n>k*(k+1)/2)
        {
            ++k;
        }
        return k;
    }
};