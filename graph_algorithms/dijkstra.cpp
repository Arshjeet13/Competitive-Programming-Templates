const int N = 2e5+3;
const int INF = 1e17+3;
vector<pair<int,int>> g[N];
int vis[N];
vector<int> dist(N, INF);

void dijkstra(int src){

    set<pair<int,int>> st;
    st.insert({0, src});
    dist[src] = 0;

    while(st.size() > 0){
        auto [dist_v, v] = *st.begin();
        st.erase(st.begin());

        if(vis[v]) continue;
        vis[v] = 1;

        for(auto [child, wt] : g[v]){
            if(vis[child]) continue;

            if(dist[child] > dist[v] + wt){
                dist[child] = dist[v] + wt;
                st.insert({dist[child], child});
            }
        }
    }
}