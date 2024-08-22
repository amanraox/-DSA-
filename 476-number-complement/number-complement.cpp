class Solution {
public:
    int findComplement(int num) {
        unsigned int bit=0,k=0;
        while(k<=num)bit++,k=pow(2,bit);
        return (k-1)^num;
    }
};