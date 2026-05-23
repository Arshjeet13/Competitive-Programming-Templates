int INF = 1e15+3;
vector<vector<int>> edges;

for(int i=0; i<n-1; ++i){
    bool changed = false;

    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if(dist[u] != INF){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                changed = true;
            }           
        }
    }

    if(!changed){
        break;
    }
}

// After running one more iteration of the bellman ford, atleast one node from
// every single negative cycle (reachable from the source) must be present in vec
// Moreover, it may also contain nodes not belonging to any negative cycle but
// reachable from some negative cycle(s)
vector<int> vec;
for(auto edge : edges){
    int u = edge[0];
    int v = edge[1];
    int w = edge[2];

    if(dist[u] != INF){
        if(dist[v] > dist[u] + w){
            vec.pb(v);
        }
    }
}
