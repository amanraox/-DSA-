class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
      priority_queue<pair<int,int>>maxH;
      for(int i=0;i<nums.size();i++){
          maxH.push({nums[i],i});
          if(i>=(k-1)){
              while(i - maxH.top().second >= k){
                  maxH.pop();
              }
              res.push_back(maxH.top().first);
          }
      }  
      return res;
    }
};