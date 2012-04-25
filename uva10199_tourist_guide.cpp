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
#define round(x) x <= 0.5 ? floor(x) : ceil(x)
#ifdef DEBUG
#define debug(x) x
#else
#define debug(x)
#endif
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

int instancia = 1, V, A, qtd_arestas;
map<int, string> nomes;
map<string, int> vertices;
vector<vector<int> > G;
vector<int> articulacoes;
int conta_pre;
vector<string> resposta;
vector<int> pre, low, parnt;


void articulacoes_recursivo(int v){
	bool articulacao = false;
	int conta_filhos = 0;
	pre[v] = conta_pre++;
	low[v] = pre[v];
	
	f(i, 0, G[v].size()){
		int w = G[v][i];
		if(pre[w] == -1){
			parnt[w] = v;
			conta_filhos++;
			
			articulacoes_recursivo(w);
			if(low[w] < low[v])
				low[v] = low[w];
			if(parnt[v] != v && low[w] >= pre[v])
				articulacao = true;
		} else if(w != parnt[v] && pre[w] < low[v])
			low[v] = pre[w];
	}
	
	debug(cout << nomes[v] << " " << pre[v] << " " << low[v] << endl;)
	if(articulacao || parnt[v] == v  && conta_filhos > 1)
		articulacoes.pb(v);
}

void calcular_articulacoes(){
	pre.clear();
	low.clear();
	parnt.clear();

	pre.insert(pre.begin(), V, -1);
	low.insert(low.begin(), V, -1);
	parnt.insert(parnt.begin(), V, -1);
	
	conta_pre = 0;

	f(v, 0, V){
		if(pre[v] == -1){
			parnt[v] = v;
			articulacoes_recursivo(v);
		}
	}
}

int main(){
	bool primeiro = true;
	int qtd_instancias = 0;

	while(cin >> V && V != 0){
		if(!primeiro)
			cout << endl;
		primeiro = false;
	
		qtd_instancias++;
		G.clear();
		nomes.clear();
		vertices.clear();
		articulacoes.clear();
		
		G.insert(G.begin(), V, vector<int>());
		
		string nome;
		f(i, 0, V){
			cin >> nome;
			nomes[i] = nome;
			vertices[nome] = i;
		}
		
		cin >> A;
		getchar();
		
		string origem, destino;
		f(i, 0, A){
			getline(cin, origem, ' ');
			getline(cin, destino);
			
			G[vertices[origem]].pb(vertices[destino]); 
			G[vertices[destino]].pb(vertices[origem]); 
		}
		
		calcular_articulacoes();
		
		resposta.clear();
		f(i, 0, articulacoes.size()){
			resposta.pb(nomes[articulacoes[i]]);
			
		}
		
		sort(resposta.begin(), resposta.end());
		
		cout << "City map #" << qtd_instancias << ": "<< articulacoes.size() << " camera(s) found" << endl;
		f(i, 0, articulacoes.size()){
			cout << resposta[i] << endl;
		}

	}
	
	return 0;
}
