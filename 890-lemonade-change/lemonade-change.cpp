class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fi=0,te=0;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)++fi;
            else if(bills[i]==10)--fi,++te;
            else if(te)--te,--fi;
            else fi-=3;
            if(fi<0)return 0;
        }
        return 1;
    }
};