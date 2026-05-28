const int N = 100;
const int INF = 1e18+3;
int d[N][N];

for(int k=1; k<=n; ++k){
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(d[i][k] < INF && d[j][k] < INF){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }            
        }
    }
}

// Existence of a shortest path check b/w nodes u and v
int u,v;
bool negCycle = false;
for(int i=1; i<=n; ++i){
    if(d[u][i] != INF && d[i][v] != INF && d[i][i] < 0){
        negCycle = true;
        break;
    } 
}