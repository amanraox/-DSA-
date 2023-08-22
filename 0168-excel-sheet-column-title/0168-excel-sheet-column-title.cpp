class Solution {
public:
    string convertToTitle(int cn) {
        string ans="";
        while(cn>26)
        {
            int m=cn%26;
            if(m==0)
            {
              ans='Z'+ans;
              cn/=26;
              cn--;
            }
            else
            {
              ans=char(64+m)+ans;
              cn/=26;
            }
        }
        return char(64+cn)+ans;
    }
};