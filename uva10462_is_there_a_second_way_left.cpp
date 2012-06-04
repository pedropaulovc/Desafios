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
#include<climits>
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
#define round(x) x <= 0.5 ? floor(x) : ceil(x)
#ifdef DEBUG
#define debug(x) x
#else
#define debug(x)
#endif
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

typedef struct {
	int v, w;
	double cost;
	bool esta_mst;
} aresta;

int V, A;
vector<aresta> arestas;
vector<int> pai, rank;


double custo;
int ignorada;

bool compara_aresta(aresta a1, aresta a2){
	return a1.cost < a2.cost;
}

void inicializa_unionfind(int n){
	pai.clear();
	rank.clear();
	
	f(i, 0, n){
		pai.pb(i);
		rank.pb(1);
	}
}

int acha_pai(int v){
	if(pai[v] == v)
		return v;
	return acha_pai(pai[v]);
}

int uniao(int v, int w){
	v = acha_pai(v);
	w = acha_pai(w);
	
	if(rank[v] < rank[w])
		swap(v, w);
	
	pai[w] = v;
	rank[v] += rank[w];
	
	return v;
}


bool kruskal(bool ignorar){
	debug(cout << ignorar << endl);
	inicializa_unionfind(V + 1);
	
	aresta a;
	int componentes = V;
	custo = 0.;
	int i = 0;
	while(componentes != 1 && i < A){
		if(ignorar && i == ignorada){
			i++;
			continue;
		}
			
		a = arestas[i];
	
		if(acha_pai(a.v) != acha_pai(a.w)){
			debug(cout << a.v << " " << a.w << " " << a.cost << endl);
			uniao(a.v, a.w);
			custo += a.cost;
			componentes--;
			if(!ignorar)
				arestas[i].esta_mst = true;
		}
		
		i++;
	}
	
	debug(cout << custo << endl);
	if(componentes == 1)
		return true;
	return false;
}

int main(){
	int qtd_testes;
	cin >> qtd_testes;
	
	f(i, 1, qtd_testes + 1){
		arestas.clear();
		cin >> V >> A;
		
		aresta a;
		f(j, 0, A){
			cin >> a.v >> a.w >> a.cost;
			arestas.pb(a);
		}
		
		sort(all(arestas), compara_aresta);
		if(!kruskal(false)){
			cout << "Case #" << i << " : No way" << endl;
			continue;
		}
		
		double min = INT_MAX;
		for(ignorada = 0; ignorada < A; ignorada++){
			if(!arestas[ignorada].esta_mst)
				continue;
			if(kruskal(true) && custo < min)
				min = custo;
		}
		
		if(min == INT_MAX)
			cout << "Case #" << i << " : No second way" << endl;
		else
			cout << "Case #" << i << " : " << min << endl;
	}
	
	return 0;
}
