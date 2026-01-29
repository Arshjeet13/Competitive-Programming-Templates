#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define fast() ios::sync_with_stdio(false); cin.tie(NULL)
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int MOD = 998244353;
 
int exp(int a, int b) {
    if (b == 0) return 1;
    if (b ==  1) return a;
    int half = exp(a, b/2) % MOD;
    int ans = (half * half) % MOD;
    if (b&1) {ans *= a; ans %= MOD;}
    return ans;
}
 
signed main(){
    fast();
 
    //int tc = 1;
    int tc; cin>>tc;
    while(tc--){

        
    }
}

