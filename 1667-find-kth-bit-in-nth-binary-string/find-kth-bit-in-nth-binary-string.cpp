class Solution {
public:
    char findKthBit(int n, int k) {
        if (k==1) return '0';
        if ((1<<32-__builtin_clz(k))-k==k) return '1';
        return (findKthBit(n, (1<<32-__builtin_clz(k))-k)=='0')?'1':'0';
    }
};