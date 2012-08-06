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

int n, t, m;
vector<int> chegadas;
int pd_tempo[1440][1440];
int pd_viagens[1440][1440];

int qtd_disponiveis(int falta, int tempo){
	int i = falta - m;
	int qtd = 0;
	while(i < m && chegadas[i] <= tempo && qtd < n){
		i++;
		qtd++;
	}
		
	return qtd;
}

typedef stuct {
	int v, t;
} viagens_tempo;

viagens_tempo minimo(viagens_tempo vt1, viagens_tempo vt2){
	if(vt1.t != vt2.t)
		return vt1.t < vt2.t ? vt1 : vt2;
	return vt1.v < vt2.v ? vt1 : vt2;
}

viagens_tempo solve(int falta, int tempo, int viagens){
	viagens_tempo vt, vt_min;
	if(falta == 0){
		vt.v = viagens;
		vt.t = tempo;
		
		return vt;
	}
	
	if(pd_tempo[falta][tempo] != -1){
		vt.t = pd_tempo[falta][tempo];
		vt.v = pd_viagens[falta][viagens];
		
		return vt;
	}
	
	//Minimo entre partir agora e aguardar mais um carro
	int disp = qtd_disponiveis(falta, tempo);
	vt_min = minimo(solve(falta - qtd, tempo + 2 * t, viagens + 1), solve(falta, tempo + 2 * t, viagens + 1));
	
}

int main(){
	int qtd_testes;
	cin >> qtd_testes;
	
	int chegada;
	f(t, 0, qtd_testes){
		cin >> n >> t >> m;
		f(i, 0, m){
			cin >> chegada;
			chegadas.pb(chegada);
		}
		
		//TODO Limpar PD
		solve(m, chegadas[0], 0);
	}	
	
	
	return 0;
}
