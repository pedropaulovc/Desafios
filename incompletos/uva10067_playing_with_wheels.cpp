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

#define contem(a, b) (a.find(b) != a.end())
#define prox(a) a == 9 ? 0 : a + 1
#define ant(a) a == 0 ? 9 : a - 1

typedef struct {
	int a, b, c, d;
} estado;

estado inicial, final;
set<estado> proibidos;
int qtd_proibidos;
queue<estado> fila;
map<estado, int> distancia;
map<estado, estado> pai;
estado novo, atual;

bool operator==(estado a, estado b){
	return a.a == b.a && a.b == b.b && a.c == b.c && a.d == b.d;
}

bool operator!=(estado a, estado b){
	return !(a == b);
}

bool operator<(estado a, estado b){
	if(a.a != b.a)
		return a.a < b.a;
	if(a.b != b.b)
		return a.b < b.b;
	if(a.c != b.c)
		return a.c < b.c;
	if(a.d != b.d)
		return a.d < b.d;
	return false;
}

ostream& operator<< (ostream &out, estado &a) {
    out << "[" << a.a << ", " << a.b << ", " << a.c << ", " << a.d << "]";
    return out;
}

void imprimir_caminho(){
	cout << "CAMINHO:" << endl;
	atual = final;
	while(atual != inicial){
		cout << atual << endl;
		atual = pai[atual];
	}
	cout << inicial << endl;
}

void inserir_novo_estado(estado e){
	if(!contem(proibidos, e) && !contem(distancia, e)){
		distancia[e] = distancia[atual] + 1;
		fila.push(e);
		debug(pai[e] = atual);
	}
}

int calcular_distancia(){
	while(!fila.empty())
		fila.pop();
	distancia.clear();
	debug(pai.clear());
	atual = inicial;
	
	if(contem(proibidos, inicial) || contem(proibidos, final))
		return -1;
	
	fila.push(atual);
	distancia[atual] = 0;
	debug(pai[atual] = atual);
	
	while(!fila.empty() && atual != final){
		atual = fila.front();
		fila.pop();
		debug(cout << atual << endl);
		
		novo = atual;
		novo.a = prox(novo.a);
		inserir_novo_estado(novo);
		
		novo = atual;
		novo.a = ant(novo.a);
		inserir_novo_estado(novo);
		
		novo = atual;
		novo.b = prox(novo.b);
		inserir_novo_estado(novo);
		
		novo = atual;
		novo.b = ant(novo.b);
		inserir_novo_estado(novo);
		
		novo = atual;
		novo.c = prox(novo.c);
		inserir_novo_estado(novo);
		
		novo = atual;
		novo.c = ant(novo.c);
		inserir_novo_estado(novo);
		
		novo = atual;
		novo.d = prox(novo.d);
		inserir_novo_estado(novo);
		
		novo = atual;
		novo.d = ant(novo.d);
		inserir_novo_estado(novo);
	}
	
	if(atual == final){
		debug(imprimir_caminho());
		return distancia[final];
	}
	return -1;
}

int main(){
	int qtd_testes;
	cin >> qtd_testes;
	
	f(i, 0, qtd_testes){
		cin >> inicial.a >> inicial.b >> inicial.c >> inicial.d;
		cin >> final.a >> final.b >> final.c >> final.d;
		
		cin >> qtd_proibidos;
		estado e;
		f(j, 0, qtd_proibidos){
			cin >> e.a >> e.b >> e.c >> e.d;
			proibidos.insert(e);
		}
		
		cout << calcular_distancia() << endl;
	}

	return 0;
}


