class Solution {
public:
    int countVowelPermutation(int n) {
        vector<long> dp0(k, 1);
        vector<long> dp1(k);

        for (int x = 2; x <= n; x++) {
            dp1[a] = (dp0[e] + dp0[i] + dp0[u]) % MOD;  // ea, ia, ua
            dp1[e] = (dp0[a] + dp0[i]) % MOD;           // ae, ie
            dp1[i] = (dp0[e] + dp0[o]) % MOD;           // ei, oi
            dp1[o] = dp0[i];                            // io
            dp1[u] = (dp0[i] + dp0[o]) % MOD;           // iu, ou
            swap(dp0, dp1);
        }
        
        return (dp0[a] + dp0[e] + dp0[i] + dp0[o] + dp0[u]) % MOD;
    }
    enum vowel {
        a,
        e,
        i,
        o,
        u,
        k,
    };
    const int MOD = 1e9 + 7;  
};