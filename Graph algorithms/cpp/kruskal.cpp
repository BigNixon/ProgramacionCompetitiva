#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5+15;
vector<pair<int,int> > G[MX];
vector<int> MST[MX];
vector<pair<int,pair<int,int>>> E;
int n,m;

int F[MX],H[MX];

int fth(int x){
    if(x==F[x]) return x;
    return F[x] = fth(F[x]);
}

void union_find(int u, int v){
    if(H[u]<H[v]) F[u] = v;
    else{
        F[v] = u;
        if(H[u]==H[v]) H[u]++;
    }
}

void init(){
    for(int i=1; i<=n; i++){
        F[i] = i;
        H[i] = 1;
    }
}

void kruskal(){
    init();
    for(int i=0; i<m; i++){
        int u = E[i].second.first;
        int v = E[i].second.second;
        if(fth(u)!=fth(v)){
            union_find(fth(u),fth(v));
            MST[u].push_back(v);
            MST[v].push_back(u);
        }
    }
}


int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
        E.push_back(make_pair(w,make_pair(u,v)));
    }
    sort(E.begin(),E.end());            //ordeno las aristas de menor a mayor según su peso
    kruskal();
    return 0;
}