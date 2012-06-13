#include<iostream>
#include<iomanip>
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

map<string, int> vertices;
map<int, string> nomes;
vector<vector<int> > G(100);
vector<int> ordenamento_topologico;
int V, A;

class comparador {
public:
	bool operator() (const int& lhs, const int&rhs) const {
		return (lhs>rhs);
	}
};


void imprimir_grafo(){
	f(v, 0, V){
		cout << nomes[v] << ": ";
		f(j, 0, G[v].size())
			cout << nomes[G[v][j]] << " ";
		cout << endl;
	}
}

void calcular_ordenamento_topologico(){
	vector<int> grau_entrada(V);
	priority_queue<int, vector<int>, comparador> fila;
	ordenamento_topologico.clear();
	
	f(v, 0, V)
		f(j, 0, G[v].size())
			grau_entrada[G[v][j]]++;
			
	f(v, 0, V)
		if(grau_entrada[v] == 0)
			fila.push(v);
	
	int fonte, w;
	f(i, 0, V){
		fonte = fila.top();
		fila.pop();
		
		ordenamento_topologico.pb(fonte);
		f(j, 0, G[fonte].size()){
			w = G[fonte][j];
			grau_entrada[w]--;
			if(grau_entrada[w] == 0)
				fila.push(w);
		}
	}
}

int main(){
	string bebida, bebida2;
	int instancia = 1;

	while(cin >> V){
		f(i, 0, V)
			G[i].clear();
		nomes.clear();
		vertices.clear();
	
		f(i, 0, V){
			cin >> bebida;
			if(vertices.find(bebida) != vertices.end())
				continue;
			nomes[i] = bebida;
			vertices[bebida] = i;
		}
		
		cin >> A;
		f(i, 0, A){
			cin >> bebida >> bebida2;
			vector<int> &adj = G[vertices[bebida]];
			
			if(find(all(adj), vertices[bebida2]) == adj.end())
				G[vertices[bebida]].pb(vertices[bebida2]);
		}
		
		calcular_ordenamento_topologico();
		
		cout << "Case #" << instancia << ": Dilbert should drink beverages in this order: ";
		f(i, 0, V - 1)
			cout << nomes[ordenamento_topologico[i]] << " ";
		cout << nomes[ordenamento_topologico[V - 1]] << "." << endl << endl;
		instancia++;
	}

	return 0;
}
