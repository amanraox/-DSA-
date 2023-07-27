class Solution {
public:
    int k;
    bool f(vector<int>& batteries, const int n, const long long &m){
        long long sum=0;
        for(int i: batteries)
            sum+=min((long long)i,m);
        return sum/n >= m;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries){
        k=batteries.size();
        if(k<n) return 0;
        if(k==n)    return *min_element(batteries.begin(),batteries.end());
        long long l=1, r=1e15;
        while(r>l+1){
            long long m=(l+r)/2;
            if(f(batteries,n,m))
                l=m;
            else
                r=m;
        }
        return l;
    }
};