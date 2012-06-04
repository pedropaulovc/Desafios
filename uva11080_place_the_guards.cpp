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

vector<vector<int> > G(200);
int V, A, qtd_testes;
vector<int> cor(200);
int contador[2];

bool dfs_bicoloracao(int v, int cor_atual){
	cor[v] = cor_atual;
	contador[cor_atual]++;
	
	f(i, 0, G[v].size()){
		int w = G[v][i];
		if(cor[w] == cor_atual || cor[w] == -1 && !dfs_bicoloracao(w, 1 - cor_atual))
			return false;
	}
	
	return true;
}

int calcular_min_guardas(){
	int total = 0;
	int minimo;
	
	f(v, 0, V)
		cor[v] = -1;
	f(v, 0, V){
		if(cor[v] == -1) {
			contador[0] = contador[1] = 0;
			if(!dfs_bicoloracao(v, 0))
				return -1;
			minimo = min(contador[0], contador[1]);
			total += max(minimo, 1);
		}
	}
	
	return total;
}

int main(){
	cin >>  qtd_testes;
	
	int v, w;
	f(i, 0, qtd_testes){
		f(j, 0, V)
			G[j].clear();
					
		cin >> V >> A;
		f(j, 0, A){
			cin >> v >> w;
			if(find(all(G[v]), w) == G[v].end())
				G[v].pb(w);
			if(find(all(G[w]), v) == G[w].end())
				G[w].pb(v);
		}
		
		cout << calcular_min_guardas() << endl;
	}
	return 0;
}
