const int N = 2e5+3;
int parent[N];
int sz[N];

void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v){
    if(v == parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int u, int v){
    u = find_set(u);
    v = find_set(v);

    if(u == v) return;

    if(sz[u] > sz[v]) swap(u,v);
    parent[u] = v;
    sz[v] += sz[u];
}


