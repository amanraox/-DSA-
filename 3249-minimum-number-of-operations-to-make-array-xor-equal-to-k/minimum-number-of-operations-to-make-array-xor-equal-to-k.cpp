class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
     int a  = 0;
        for(int i=0; i<nums.size(); i++) {
            a ^= nums[i];
        }

        bitset<sizeof(a) * 8> num1(a);
        bitset<sizeof(k) * 8> num2(k);

        int res = 0;
        for(int i=0; i<num1.size(); i++) {
            if(num1[i] != num2[i]) res++;
        }
        return res;
    }
};