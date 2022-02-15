#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,M;
	string txt,pat;
	cin>>txt>>pat;
	N=txt.size(),M=pat.size();
	int  i=1,len=0;
	vector<int> lps(M),ans(N);
	while(i<M){
	    if(pat[len]==pat[i]){
	        lps[i]=len+1;
	        len++,i++;
	    }
	    else{
	        if(len==0){
	            lps[i]=0;
	            i++;
	        }
	        else{
	            len=lps[len-1];
	        }
	    }
	}
	i=0;        //iterador del txt
	int j=0;    //iterador del patron de búsqueda pat
	while(i<N){
	    if(txt[i]==pat[j]){
	        ans[i]=j+1;
	        i++,j++;
	    }
	    else{
	        if(j!=0) j=lps[j-1];
	        else{
	            ans[i]=0;
	            i++;
	        }
	    }
	    if(j==M){
	        j=lps[j-1];
	    }
	}
	for(int i=0;i<N;i++) if(ans[i]==M) cout<<i-M+1<<endl;
	
	return 0;
}
