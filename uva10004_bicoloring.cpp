#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<list>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++ )
#define FORV(it,A) for(vector<int>::iterator it = A.begin(); it!= A.end(); it++)
#define FORS(it,A) for(set<int>::iterator it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
#ifdef DEBUG
#define debug(x) x
#else
#define debug(x)
#endif
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

vector<vector<int> > G;
vector<int> coloracao;
int V, A;

bool dfs_coloracao(int v, int cor){
	debug(cout << "cor[" << v << "] = " << cor << endl);
	coloracao[v] = cor;
	
	f(i, 0, G[v].size()){
		if(coloracao[G[v][i]] == -1)
			dfs_coloracao(G[v][i], 1 - cor);
		else if(coloracao[G[v][i]] != 1 - cor) {
			debug(cout << "cor[" << v << "] != " << 1 - cor << endl);
			return false;
		}
		
	}
	
	return true;
}

bool bicolorivel(){
	coloracao.clear();
	coloracao.insert(coloracao.begin(), V, -1);
	
	return dfs_coloracao(0, 0);
}

int main(){
	int v, w;

	while(cin >> V && V > 0){
		G.clear();
		G.insert(G.begin(), V, vector<int>());
		
		cin >> A;
		f(i, 0, A){
			cin >> v >> w;
			G[v].pb(w);
			G[w].pb(v);
		}
		
		if(bicolorivel())
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;
	}
	
	return 0;
}

