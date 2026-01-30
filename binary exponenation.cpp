const int MOD = 998244353;
 
/*
Returns a^b modulo MOD
*/
int exp(int a, int b) {
    if (b == 0) return 1;
    if (b ==  1) return a;
    int half = exp(a, b/2) % MOD;
    int ans = (half * half) % MOD;
    if (b&1) {ans *= a; ans %= MOD;}
    return ans;
}
