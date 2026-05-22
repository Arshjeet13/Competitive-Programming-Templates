// ITERATIVE
const int N = 1001;
int C[N][N];

for(int i=1; i<=n; ++i){
    C[i][0] = C[i][i] = 1;
}

for(int i=1; i<=n; ++i){
    for(int j=1; j<i; ++j){
        C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
}

// USING BINARY EXPONENATION
// nCr = n!/r!(n-r)!
// So, we can calculate 2 factorial arrays
// f[N] and invf[N]
// where f[i] = i! and invf[i] = inverse of i! modulo MOD
int f[N];
int invf[N];
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

int C(int n, int r){
    return (((f[n] * invf[r]) % MOD) * invf[n-r]) % MOD;
}

int main(){

    f[0] = 1;
    for(int i=1; i<N; ++i){
        f[i] = (f[i-1] * i) % MOD;
    }

    invf[N-1] = exp(f[N-1], MOD-2);
    for(int i=N-1; i>=1; --i){
        invf[i-1] = (invf[i] * i) % MOD;
    }
}

