class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || n==2)
        return false;
        vector<int> pref(n,INT_MAX);
        for(int i=1; i<n; i++){
            pref[i] = min(nums[i-1], pref[i-1]);
        }
        set<int> st;
        st.insert(nums[n-1]);
        for(int i=n-1; i>=1; i--){
            if(pref[i] + 1 < nums[i]){
               auto it = st.lower_bound(pref[i]+1);
               if(it != st.end() && (*it) < nums[i])
               return true;
            }
            st.insert(nums[i]);
        }
        return false;
    }
};