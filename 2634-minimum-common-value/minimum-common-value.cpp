class Solution {
public:
    int getCommon(vector<int>& n1, vector<int>& n2) {
        int s1=n1.size(),s2=n2.size();
        if (n1[s1-1] < n2[0] || n2[s2-1] < n1[0]) return -1;
        for(int i=0,j=0;i<s1 and j<s2;)
        {
            if(n1[i]==n2[j])return n1[i];
            else if(n1[i]>n2[j])++j;
            else ++i;
        }
        return -1;
    }
};