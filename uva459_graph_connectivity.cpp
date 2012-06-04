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

int qtd_testes, V, A;
char max_vertice;
vector<vector<int> > G;
map<int, char> nomes;
map<char, int> vertices;
vector<int> parnt;

void visitar(int v){
	f(i, 0, G[v].size()){
		int w = G[v][i];
		
		if(parnt[w] == -1){
			parnt[w] = v;
			visitar(w);
		}
	}
}

int calcula_qtd_componentes(){
	int componentes = 0;
	
	parnt.clear();
	parnt.insert(parnt.begin(), V, -1);
	
	f(i, 0, V){
		if(parnt[i] == -1){
			parnt[i] = i;
			visitar(i);
			
			componentes++;
		}
	}
	
	return componentes;
}

void imprime(){
	f(i, 0, G.size()) {
		cout << i << ": ";
		f(j, 0, G[i].size())
			cout << G[i][j] << " ";
		cout << endl;
	}
}

int main (){
	cin >> qtd_testes;
	
	bool primeiro = true;
	f(i, 0, qtd_testes){
		if(!primeiro)
			cout << endl;
		primeiro = false;
		
		G.clear();
		cin >> max_vertice;
		getchar();
		
		V = max_vertice - 'A' + 1;
		G.insert(G.begin(), V, vector<int>());
	
		string linha;
		int v_atual = 0;
		while(getline(cin, linha) && linha != ""){
			int v = linha[0] - 'A';
			int w = linha[1] - 'A';
			if(find(G[v].begin(), G[v].end(), w) == G[v].end())
				G[v].pb(w);
			if(find(G[w].begin(), G[w].end(), v) == G[w].end())
				G[w].pb(v);
			
			debug(cout << "\"" << linha << "\"" << endl);
		}
		
		debug(imprime());
		
		cout << calcula_qtd_componentes() << endl;
	}
	
	
	return 0;
}
