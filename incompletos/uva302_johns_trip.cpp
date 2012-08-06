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

class aresta {
public:
	int num, w;
	
	bool operator==(aresta a) {
		return num == a.num && w == a.w;
	}	
};

stack<int> caminho;
vector<list<aresta> > G(2000);
int V;

bool possui_ciclo_euleriano(){
	f(i, 0, V)
		if(G[i].size() % 2 == 1)
			return false;
	return true;
}

/*
'tour' is a stack

find_tour(u):
	for each edge e=(u,v) in E:
		remove e from E
		find_tour(v)
	prepend u to tour

to find the tour, clear stack 'tour' and call find_tour(u),
where u is any vertex with a non-zero degree.
*/

bool compara(aresta a1, aresta a2){
	return a1.num < a2.num;
}

void calcular_ciclo_euleriano(int v){
	aresta sai, atual;
	sai.w = v;
	
	for(list<aresta>::iterator it = G[v].begin(); it!= G[v].end(); it++){
		atual = *it;
		sai.num = atual.num;
		G[v].pop_front();
		G[atual.w].remove(sai);
		calcular_ciclo_euleriano(atual.w);
	}
	caminho.push(v);
}

int main(){
	int v;
	aresta a;
	
	while(cin >> v >> a.w >> a.num){
		if(v == 0 && a.w == 0)
			break;
		V = 0;
		f(i, 0, 2000)
			G[i].clear();

		G[v].pb(a);
		swap(a.w, v);
		G[v].pb(a);
		V = max(V, v);
		V = max(V, a.w);
		while(cin >> v >> a.w >> a.num){
			if(v == 0 && a.w == 0)
				break;
			G[v].pb(a);
			swap(a.w, v);
		 	G[v].pb(a);
			 	
			V = max(V, v);
			V = max(V, a.w);
		}
		
		if(!possui_ciclo_euleriano()){
			cout << "Round trip does not exist." << endl;
			continue;
		}
		
		f(i, 0, V)
			G[i].sort(compara);
		
		while(!caminho.empty())
			caminho.pop();
		calcular_ciclo_euleriano(1);
		
		while(!caminho.empty()){
			cout << caminho.top() << " ";
			caminho.pop();
		}
	}
	
	return 0;
}
