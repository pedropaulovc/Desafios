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
	int w;
	double cost;
} adj;


#define maxCST INT_MAX
#define maxV 10000
#define SENTINELA V
double cst[maxV];
int parnt[maxV];
vector<vector<adj> > G(10000);
int V, A;



bool bellmanford(int s) {
	int v, w; int k=0;
	for (v = 0; v < V; v++) {
		cst[v] = maxCST;
		parnt[v] = -1;
	}
	
	queue<int> fila;
	cst[s] = 0;
	parnt[s] = s;
	fila.push(s);
	fila.push(SENTINELA);
	
	while (!fila.empty()) {
		v = fila.front();
		fila.pop();
		if (v == SENTINELA) {
			if (k++ == V) {
				if (!fila.empty()) {
					return false;
				}
				return true;
			}
			fila.push(SENTINELA);
		} else
			f(i, 0, G[v].size())
				if(cst[w = G[v][i].w] > cst[v] + G[v][i].cost) {
					cst[w] = cst[v] + G[v][i].cost;
					parnt[w] = v;
					fila.push(w);
				}
	}
}

int main() {
	int qtd_testes;
	
	cin >> qtd_testes;
	
	f(i, 0, qtd_testes){
		f(i, 0, 1000)
			G[i].clear();
			
		cin >> V >> A;
		
		int v;
		adj adjacente;
		f(i, 0, A){
			cin >> v >> adjacente.w >> adjacente.cost;
			
			G[v].pb(adjacente);
		}

		if(bellmanford(0))
			cout << "not possible" << endl;
		else
			cout << "possible" << endl;
	}
	return 0;
}
