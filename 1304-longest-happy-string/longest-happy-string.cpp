class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s="";
        int ca,cb,cc;ca=cb=cc=0;
        while(a or b or c)
        {
            if(a>=b and a>=c){
                if(b==0 and c==0 and ca==2)return s;
                if(ca==2)
                {
                    if(b>=c)ca=0,++cb,--b,cc=0,s+="b";
                    else ca=0,--c,cb=0,cc++,s+="c";
                }
                else cb=0,cc=0,++ca,--a,s+="a";
            }
            else if(b>=a and b>=c){
                if(a==0 and c==0 and cb==2)return s;
                if(cb==2)
                {
                    if(a>=c)cb=0,cc=0,++ca,--a,s+="a";
                    else ca=0,--c,cb=0,cc++,s+="c";
                }
                else ca=0,++cb,--b,cc=0,s+="b";
            }
            else if(c>=a and c>=b){
                if(b==0 and a==0 and cc==2)return s;
                if(cc==2)
                {
                    if(b>=a)ca=0,++cb,--b,cc=0,s+="b";
                    else cb=0,cc=0,++ca,--a,s+="a";
                }
                else cb=0,ca=0,++cc,--c,s+="c";
            }
        }
        return s;
    }
};