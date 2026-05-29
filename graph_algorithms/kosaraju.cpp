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

const int N = 1e5+3;
vector<int> g[N];
vector<int> rg[N];
vector<int> post_order;
int vis[N];
vector<int> scc;
vector<vector<int>> components;

void reset(int n){
    scc.clear();
    components.clear();
    post_order.clear();
    for(int i=1; i<=n; ++i){
        vis[i] = 0;
        g[i].clear();
        rg[i].clear();
    }
}

void dfs1(int v){
    vis[v] = 1;
    for(auto child : rg[v]){
        if(vis[child]) continue;
        dfs1(child);
    }

    post_order.pb(v);
}

void dfs2(int v){
    vis[v] = 1;
    for(auto child : g[v]){
        if(vis[child]) continue;
        dfs2(child);
    }
    scc.pb(v);
}

signed main(){
    fast();

    //int tc = 1;
    int tc; cin>>tc;
    while(tc--){

        int n; cin>>n;
        int m; cin>>m;

        reset(n);

        for(int i=0; i<m; ++i){
            int u,v; cin>>u>>v;
            g[u].pb(v);
            rg[v].pb(u);
        }

        for(int i=1; i<=n; ++i){
            if(vis[i]) continue;
            dfs1(i);
        }

        reverse(all(post_order));

        for(int i=1; i<=n; ++i) vis[i] = 0;

        for(auto v : post_order){
            if(vis[v]) continue;
            scc.clear();
            dfs2(v);
            components.pb(scc);
        }
    }
}