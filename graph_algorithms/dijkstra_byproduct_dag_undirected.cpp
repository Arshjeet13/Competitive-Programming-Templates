// This generates the dag byproduct of running dijkstra on a directed graph
// allowing one to extract min/max path lengths, etc via DP
const int N = 1e5+1;
const int INF = 1e17+3;
vector<pair<int,int>> g[N];
vector<int> dag[N];
int vis[N];
int dist[N][2];

void dijkstra(int src, int x){
    dist[src][x] = 0;
    set<pair<int,int>> st;
    st.insert({0,src});

    while(st.size() > 0){
        auto [d,v] = *st.begin();
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v] = 1;

        for(auto [child,wt] : g[v]){
            if(vis[child]) continue;

            if(dist[child][x] > dist[v][x] + wt){
                dist[child][x] = dist[v][x] + wt;
                st.insert({dist[child][x], child});
            }
        }
    }
}

void dfs(int v){
    vis[v] = 1;
    for(auto child : dag[v]){
        if(vis[child]) continue;
        dfs(child);
    }
    top.pb(v);
}

signed main(){
    fast();

    int tc = 1;
    //int tc; cin>>tc;
    while(tc--){

        int n; cin>>n;
        int m; cin>>m;
        for(int i=0; i<m; ++i){
            int u,v; cin>>u>>v;
            int wt; cin>>wt;
            g[u].pb({v,wt});
            g[v].pb({u,wt});
        }
        for(int i=1; i<=n; ++i){
            dist[i][0] = dist[i][1] = INF;
        }

        dijkstra(1,0);
        for(int i=1; i<=n; ++i) vis[i] = 0;
        dijkstra(n,1);
        for(int i=1; i<=n; ++i) vis[i] = 0;

        for(int i=1; i<=n; ++i){
            for(auto [child,wt] : g[i]){
                if(dist[i][0] + wt + dist[child][1] == dist[n][0]){
                    dag[i].pb(child);
                }
            }
        }        
    }
}