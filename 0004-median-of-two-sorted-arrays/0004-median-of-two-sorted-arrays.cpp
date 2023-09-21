class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size()+arr2.size();
        vector<int>arr3(n);
        merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), arr3.begin());
        int al=arr3.size();
        // vector<int>arty;
        sort(arr3.begin(),arr3.end());
        if(al%2==1){
            int p=((al)/2);
            return arr3[p];
        }
        else{
            int o=al/2;
            double k=(arr3[o]+arr3[o-1]);
            return ((k/2));
        }
    }
};