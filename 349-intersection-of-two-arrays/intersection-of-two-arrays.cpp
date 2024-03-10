class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        if (n1>n2) return intersection(nums2, nums1);
        bitset<1001> A=0;
        for (int x: nums1) A[x]=1;
        vector<int> ans;
        ans.reserve(1001);
        for (int x: nums2){
            if (A[x]) {
                ans.push_back(x);
                A[x]=0;
            }
        }
        return ans;
    }
};