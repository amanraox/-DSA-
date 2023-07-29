class Solution {
public:
    double rec(int a,int b, map<pair<int,int>,double>&mp)
{
    if (a<=0 && b<=0) return 0.5;
    if (a<=0) return 1;
    if (b<=0) return 0;
    if (mp.count({a,b})) return mp[{a,b}];
    double ans=0;
    ans+=rec(a-100,b,mp);
    ans+=rec(a-75,b-25,mp);
    ans+=rec(a-50,b-50,mp);
    ans+=rec(a-25,b-75,mp);
    return mp[{a,b}]= (double)ans/(double)4;
}
    double soupServings(int n) {
        if (n>=5000) return 1.0;
        map<pair<int,int>,double>mp;
        return rec(n,n,mp);
    }
};