class Solution {
public:
    string reversePrefix(string w, char ch) {
        int ind=-1;
        for(int i=0;i<w.length();i++)
        {
            if(ch==w[i]){ind=i;w[i]=w[0];w[0]=ch;break;}
        }
        if(ind == -1)return w;
        for(int i=1;i<=(ind)/2;i++)
        {
            swap(w[i],w[ind-i]);
        }
        return w;
    }
};