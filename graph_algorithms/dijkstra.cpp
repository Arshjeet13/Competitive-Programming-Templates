const int N = 2e5+3;
const int INF = LLONG_MAX;
vector<vector<int>> g[N];
int vis[N];
vector<int> dist(N, INF);

void dijkstra(int src){

    set<vector<int>> st;
    st.insert({0, src});
    dist[src] = 0;

    while(st.size() > 0){
        auto pr = *st.begin();
        int v = pr[1];
        st.erase(st.begin());

        if(vis[v]) continue;
        vis[v] = 1;

        for(auto node : g[v]){
            int child = node[0];
            int wt = node[1];

            if(vis[child]) continue;

            if(dist[child] > dist[v] + wt){
                dist[child] = dist[v] + wt;
                st.insert({dist[child], child});
            }
        }
    }
}