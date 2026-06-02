const int N = 2e5+1;
vector<int> g[N];
int anc[N][20];
 
int main(){

    int n; cin>>n;
    int q; cin>>q;
    int p[n+1];
    for(int i=2; i<=n; ++i){
        cin>>p[i];
    }

    p[1] = 0;

    for(int i=2; i<=n; ++i){
        g[i].pb(p[i]);
        g[p[i]].pb(i);
    }

    for(int i=1; i<=n; ++i){
        anc[i][0] = p[i];
    }

    for(int j=1; j<=(int)log2(n); ++j){
        anc[1][j] = 0;
        for(int i=2; i<=n; ++i){
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }

    for(int i=0; i<q; ++i){
        int x; cin>>x;
        int k; cin>>k;

        for(int j=0; j<20; ++j){
            if(k & (1LL<<j)){
                x = anc[x][j];
            }
        }
    }   
}