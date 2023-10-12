/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int ans=-1;
        int start=0, end=mountainArr.length()-1, mid=start+(end-start)/2;
        while(start<end){
            if(mountainArr.get(mid+1) < mountainArr.get(mid)){
                end = mid;
            }else{
                start = mid+1;
            }
            mid = start + (end - start)/2;
        }
        int peak=start;
        start=0, end=peak, mid = start + (end-start)/2;
        while(start<=end){
            if(mountainArr.get(mid) == target){
                ans = mid;
                end=mid-1;
            }else if(mountainArr.get(mid) > target){
                end = mid-1;
            }else{
                start = mid +1;
            }
            mid = start + (end - start)/2;
        }
        if(ans != -1){
            return ans;
        }
        start=peak, end=mountainArr.length()-1, mid = start + (end-start)/2;
        while(start<=end){
            if(mountainArr.get(mid) == target){
                ans = mid;
                end=mid-1;
            }else if(mountainArr.get(mid) > target){
                start = mid +1;
            }else{
                end = mid-1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }
};