int BIT[N];
int A[N];

int query(int x){
	int ans = 0;
	while(x){
		ans += BIT[x];
		x -= (x & (-x));
	}
	return ans;
}

void update(int node, int x){
	int y = x - A[node];
	while(node<=n){
		BIT[node] += y;
		node += (node & (-node));
	}
}

void create(){
	for(int i=0; i<=n; i++) BIT[i] = 0;
	for(int i=1; i<=n; i++){
		int j = i;
		while(j<=n){
			BIT[j] += A[i-1];
			j += (j & (-j));
		}
	}
}


//[l,r> -> query(r)-query(l)
