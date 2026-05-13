const int N = 2e5+3;
vector<int> g[N];
int vis[N];
int lvl[N];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = 1;

    while(q.size() > 0){

        int v = q.front();
        q.pop();

        for(auto child : g[v]){
            if(vis[child]) continue;
            q.push(child);
            lvl[child] = lvl[v] + 1;
            vis[child] = 1;
        }

    }
}