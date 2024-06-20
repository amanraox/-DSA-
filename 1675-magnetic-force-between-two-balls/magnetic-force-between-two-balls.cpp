class Solution {
public:
bool solve(vector<int>&nums,int mid,int m){
        int cnt=1;
        int prev=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]-prev>=mid){
                cnt++;
                prev=nums[i];
                if(cnt==m) return true;
            }
        }
        if(cnt<m)return false;
        return true;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int low=0;
        int high=position[n-1];
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(position,mid,m)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;        
    }
};