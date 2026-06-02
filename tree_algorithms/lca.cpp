const int N = 2e5+1;
vector<int> g[N];
int vis[N];
int lvl[N];
int parent[N];
int up[N][20];
int val[N];
 
void dfs(int v){
    vis[v] = 1;
    for(auto child : g[v]){
        if(vis[child]) continue;
        parent[child] = v;
        lvl[child] = lvl[v] + 1;
        dfs(child);
    }
}
 
int jump(int v, int k){
    for(int j=0; j<20; ++j){
        if(k & (1<<j)){
            v = up[v][j];
        }
    }
    return v;
}
 
int lca(int u, int v){
    if(u == v) return u;
    if(lvl[u] > lvl[v]) swap(u,v);
 
    v = jump(v, lvl[v] - lvl[u]);
 
    if(u == v) return u;
 
    for(int j=19; j>=0; --j){
        if(up[u][j] != up[v][j]){
            u = up[u][j];
            v = up[v][j];
        }
    }
 
    return up[u][0];
}
 
void build(int n){
    for(int i=1; i<=n; ++i){
        up[i][0] = parent[i];
    }
    for(int j=1; j<20; ++j){
        for(int i=1; i<=n; ++i) up[i][j] = up[up[i][j-1]][j-1];
    }
}
