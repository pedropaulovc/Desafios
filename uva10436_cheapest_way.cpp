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

map<string, int> vertices;
map<int, string> nomes;
double G[20][20];
int prox[20][20];
vector<int> pedagios;
vector<int> caminho;
int V, A;

void floyd_warshall(){
f(k, 0, V)
	f(i, 0, V)
		f(j, 0, V)
			if(G[i][k] + G[k][j] + pedagios[k] < G[i][j]){
				G[i][j] = G[i][k] + G[k][j] + pedagios[k];
				prox[i][j] = k;
			}
}

double round(double d) {
	return floor(100 * d + 0.5)/100;
}

void gera_caminho(int v, int w){
	if(G[v][w] == 10000)
		return;
	if(prox[v][w] == -1){
		return;
	}
		
	gera_caminho(v, prox[v][w]);
	caminho.pb(prox[v][w]);
	gera_caminho(prox[v][w], w);
}

int main(){
	int qtd_testes, qtd_consultas;
	cin >> qtd_testes;
	bool primeiro = true;
	f(t, 1, qtd_testes + 1){
		if(!primeiro)
			cout << endl;
		primeiro = false;
	
		vertices.clear();
		nomes.clear();
		pedagios.clear();
		
		f(i, 0, 20)
			f(j, 0, 20){
				G[i][j] = 100000;
				prox[i][j] = -1;
			}
	
		cin >> V;
		
		string nomev, nomew;
		int custo;
		f(i, 0, V){
			cin >> nomev >> custo;
			vertices[nomev] = i;
			nomes[i] = nomev;
			pedagios.pb(custo);
			G[i][i] = 0;
		}
		
		cin >> A;
		f(i, 0, A){
			cin >> nomev >> nomew >> custo;
			G[vertices[nomev]][vertices[nomew]] = 2 * custo;
			G[vertices[nomew]][vertices[nomev]] = 2 * custo;
		}
		
		floyd_warshall();
		
		cin >> qtd_consultas;
		int qtd_passageiros, v, w;
		
		cout << "Map #" << t << endl;
		f(i, 1, qtd_consultas + 1){
			cout << "Query #" << i << endl;
			cin >> nomev >> nomew >> qtd_passageiros;
			v = vertices[nomev];
			w = vertices[nomew];

			caminho.clear();
			gera_caminho(v, w);

			int tamanho = caminho.size();
			cout << nomev << " ";
			for(int j = 0; j < tamanho; j++)
				cout << nomes[caminho[j]] << " ";
			cout << nomew << endl;
			
			int preco_pedagio_pontas = pedagios[v];
			if(v != w)
				preco_pedagio_pontas += pedagios[w];
			
			cout.precision(2);
			cout << "Each passenger has to pay : " << fixed <<
				round(1.1 * (G[v][w] + preco_pedagio_pontas)/qtd_passageiros) << " taka" << endl;
		}
	}
	
	return 0;
}
