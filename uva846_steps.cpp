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

int calcula_qtd_passos(int origem, int destino){
	int passos_limite = 1;
	int meio = 1;
	int passos = 1;
	
	if(origem == destino)
		return 0;
	
	while(passos_limite < destino - origem){
		passos++;
		passos_limite += meio;
		debug(cout << passos << " ";)
		if(passos_limite >= destino - origem)
			break;
		passos++;
		passos_limite += ++meio;
		debug(cout << passos << " ";)
	}
	
	debug(cout << endl;)
	return passos;
}

int main(){
	int qtd_testes, origem, destino;
	cin >> qtd_testes;
	
	f(i, 0, qtd_testes){
		cin >> origem >> destino;
		
		if(destino < origem){
			int aux = destino;
			destino = origem;
			origem = aux;
		}
		
		cout << calcula_qtd_passos(origem, destino) << endl;
	}


	return 0;
}
