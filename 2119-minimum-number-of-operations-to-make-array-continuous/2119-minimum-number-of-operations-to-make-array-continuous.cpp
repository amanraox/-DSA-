class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int res=n;
        set<int>s(nums.begin(),nums.end());
        vector<int>v;
        for(auto i:s){
            v.push_back(i);
        }
        int j=0;
        for(int i=0;i<v.size();i++){
            while(j<v.size() && v[j]<v[i]+n){
                j++;
            }
            int count=j-i;
            res=min(res,n-count);
        }
        return res;
    }
};