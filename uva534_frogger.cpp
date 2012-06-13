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
} aresta;

typedef struct {
	double x, y;
} ponto;

int V, A;
vector<aresta> arestas;
vector<int> pai, rank;
vector<vector<aresta> > MST(201);
vector<ponto> pontos;
vector<int> lbl(201);

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


bool kruskal(){
	inicializa_unionfind(V + 1);
	
	aresta a;
	int componentes = V;
	int i = 0;
	
	sort(all(arestas), compara_aresta);
	while(componentes != 1 && i < A){
		a = arestas[i];
		
		if(acha_pai(a.v) != acha_pai(a.w)){
			uniao(a.v, a.w);
			componentes--;
			
			MST[a.v].pb(a);
			swap(a.v, a.w);
			MST[a.v].pb(a);
		}
		
		i++;
	}
	
	if(componentes == 1)
		return true;
	return false;
}

double dfs_max_distancia(int v, int objetivo){
	double max_distancia;
	lbl[v] = 1;
	if(v == objetivo)
		return 0;
	f(i, 0, MST[v].size()){
		if(lbl[MST[v][i].w] == -1) {
			max_distancia = dfs_max_distancia(MST[v][i].w, objetivo);
			if(max_distancia != -1)
				return max(max_distancia, MST[v][i].cost);
		}
	}
	
	return -1;
}

double arredonda(double num){
	return floor(num * 1000 + 0.5)/1000;	
}

int main(){
	double x, y;
	ponto p;
	aresta adj;
	int t = 1;
	while(cin >> V && V != 0){
		pontos.clear();
		arestas.clear();
		
		f(i, 0, V){
			lbl[i] = -1;
			MST[i].clear();
		}
		
		f(i, 0, V){
			cin >> p.x >> p.y;
			pontos.pb(p);
		}
		
		f(i, 0, V){
			f(j, 0, V) {
				if(i == j)
					continue;
				adj.v = i;
				adj.w = j;
				adj.cost = sqrt(quad(pontos[j].x - pontos[i].x) + quad(pontos[j].y - pontos[i].y));
				arestas.pb(adj);
			}
		}
		
		A = arestas.size();
		kruskal();
		
		cout.precision(3);
		cout << "Scenario #" << t << endl;
		cout << "Frog Distance = " << fixed << dfs_max_distancia(0, 1) << endl << endl;
		
		t++;
	}

	return 0;
}	
