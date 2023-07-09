class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        int l=0,h=n.size()-1;
        while(l<h){
            if(n[l]+n[h]>t)
            --h;
            else if(n[l]+n[h]<t)++l;
            else return {l+1,h+1};
        }
        return {l,h};
    }
};