#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,M;
	string txt,pat;
	cin>>txt>>pat;
	M=pat.size();
    txt=pat+'$'+txt;
    N=txt.size();
    int L=0,R=0,j=0;
    vector<int> Z(N);
    for(int i=1;i<N;i++){
        if(i>R){
            L=R=i;
            while(txt[R]==txt[R-L]) {
                R++;
                if(R==N) break;
            }
            Z[i]=R-L;
            R--;
        }
        else{
            if((i+Z[i-L])<=R) Z[i]=Z[i-L];
            else{
                L=i;
                while(txt[R]==txt[R-L]){
                    R++;
                    if(R==N) break;
                }
                Z[i]=R-L;
                R--;
            }
        }
    }
    for(int i=0;i<N;i++) if(Z[i]==M) cout<<i-(M+1)<<" ";
    
	return 0;
}
