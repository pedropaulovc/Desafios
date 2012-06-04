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
#define quad(x) ((x) * (x))
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
} adjacente;

typedef struct {
	double x, y;
} ponto;

int V;
vector<ponto> pontos;
vector<int> pai, rank;
vector<adjacente> arestas;

bool compara_arestas(adjacente a1, adjacente a2){
	return a1.cost < a2.cost;
}

void init (int n){
	f (i,0, n){
		pai.pb(i);
		rank.pb(1);
	}
}


int acha_pai(int v){
	if(pai[v] != v)
		return acha_pai(pai[v]);
	return v;
}

void uniao(int v, int w){
	v = acha_pai(v);
	w = acha_pai(w);
	
	if(rank[w] > rank[v])
		swap(w, v);
	rank[v] += rank[w];
	pai[w] = v;
}

int main(){
	int qtd_testes;
	
	cin >> qtd_testes;
	
	double x, y;
	ponto p;
	adjacente adj;
	bool primeiro = true;
	while(qtd_testes--){
		if(!primeiro)
			cout << endl;
		primeiro = false;
	
		pontos.clear();
		arestas.clear();
		pai.clear();
		rank.clear();
		
		cin >> V;
		
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
		
		sort(all(arestas), compara_arestas);
		
		debug(
		f(i, 0, arestas.size())
			cout << arestas[i].v << " " << arestas[i].w << " " << arestas[i].cost << endl;
		)
		
		int i = 0;
		double custo = 0;
		init(V);
		
		f(i, 0, arestas.size()){
			if(acha_pai(arestas[i].v) != acha_pai(arestas[i].w)){
				uniao(arestas[i].v, arestas[i].w);
				custo += arestas[i].cost;
			}
		}
		
		printf("%.2lf\n", custo);
	}

	return 0;
}	
