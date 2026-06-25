const int N = 2e5+3;
const int K = (int)log2(N) + 1;
int sparse[N][K];
int a[N];

void build(int n){
    for(int i=0; i<K; ++i){
        sparse[i][0] = a[i];
    }

    for(int j=1; j<20; ++j){
        for(int i=0; i + (1<<j) - 1 < n; ++i){
            sparse[i][j] = min(sparse[i][j-1], sparse[i + (1<<(j-1))][j-1]);
        }
    }
}

int query(int l, int r){
    int log = (int)log2(r-l+1);
    return min(sparse[l][log], sparse[r - (1<<log) + 1][log]);
}
