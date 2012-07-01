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

typedef struct {
	int tempo, multa, i;
} tarefa;

int qtd_tarefas;
vector<tarefa> tarefas;

bool compara(tarefa t1, tarefa t2){
	ll d1 = t1.multa * t2.tempo;
	ll d2 = t2.multa * t1.tempo;
	
	if(d1 != d2)
		return d1 > d2;
	return t1.i < t2.i;
}

int main(){
	int testes;
	cin >> testes;
	
	tarefa ta;
	bool primeiro = true;
	f(te, 0, testes){
		tarefas.clear();
		
		if(!primeiro)
			cout << endl;
		primeiro = false;

		cin >> qtd_tarefas;
		
		f(i, 1, qtd_tarefas + 1){
			ta.i = i;
			cin >> ta.tempo >> ta.multa;
			
			tarefas.pb(ta);
		}
		
		sort(all(tarefas), compara);
		
		f(i, 0, qtd_tarefas - 1)
			cout << tarefas[i].i << " ";
		cout << tarefas[qtd_tarefas - 1].i << endl;
	}
	
	return 0;
}
