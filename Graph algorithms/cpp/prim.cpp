#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5+15;
vector<pair<int,int> > G[MX];
vector<int> MST[MX];
int n,m;
bool vis[MX];

void prim(int s){
    priority_queue<pair<int,pair<int,int>>> pq;
    vis[s]=1;
    for(auto i:G[s]){
        int w = i.second;
        int v = i.first;
        int u = s;
        pq.push(make_pair(-w,make_pair(u,v)));
    }
    while(!pq.empty()){
        auto e = pq.top();
        pq.pop();
        int u = e.second.first;
        int v = e.second.second;
        if(vis[v]) continue;
        vis[v] = 1;
        MST[u].push_back(v);
        MST[v].push_back(u);
        for(auto i:G[v]){
            if(vis[i.first]) continue;
            pq.push(make_pair(-i.second,make_pair(v,i.first)));
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
    }
    prim(1);
    return 0;
}