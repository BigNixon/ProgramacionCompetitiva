#include <bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i < b; i++)
#define fst first
#define snd second
#define ll long long
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ci2(x,y) cin>>x>>y;
#define ci3(x,y,z) cin>>x>>y>>z;
#define ci4(x,y,z,w) cin>>x>>y>>z>>w;
#define co2(x,y) cout<<x<<" "<<y<<endl;
#define co3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define co4(x,y,z,w) cout<<x<<" "<<y<<" "<<z<<" "<<w<<endl;
#define pii pair<int,int>
#define piii pair<int, pii>
#define pll pair<ll,ll>
#define vi vector<int>
#define vii vector<pii>
#define viii vector<piii>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define Vector Point
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define openio freopen("in","r",stdin);freopen("out","w",stdout)
#define closeio fclose(stdin);fclose(stdout)
#define EPS 1e-8
#define PI acos(-1)
#define Vector Point

using namespace std;

const int N = 14;
vi vis(N,0);
vi graph[N]; //grafo sin pesos
//grafo con pesos vii adj[N];       adj[u].pb({v,w})

// edge list vii V;                 V.pb({u,v})
// edge list    vector<tuple<int,int,int>> v;
//              V.pb(make_tuple(u,v,w))

void dfs(int source){
    if(vis[source]){
        return;
    }
    vis[source]=1;
    //procesamos el nodo s
    for(auto u: graph[source]){
        dfs(u); //recursion del vecino
    }
}


queue <int> q;
int dis[N];

void bfs(int source){
    q.push(source);
    vis[source]=1;
    dis[source]=0;

    while(!q.empty()){
        int s = q.front();
        q.pop();

        //procesamos el nodo u
        for(auto u: graph[s]){
            if(vis[u]) return;
            
            vis[u] = 1;
            dis[u] = dis[s]+1;
            q.push(u);
        }
    }

}


int main(){
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    for(int i=1;i<=n;i++){
        for(auto u: graph[i]){
            cout<<u;
        }   
        cout<<endl;
    }

    return 0;
}