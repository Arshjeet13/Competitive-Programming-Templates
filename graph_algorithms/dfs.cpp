int N = 2e5+3;
vector<int> g[N];
int vis[N];

void dfs(int v){
    vis[v] = 1;

    for(auto child : g[v]){
        if(vis[child]) continue;

        dfs(child);

    }

    
}