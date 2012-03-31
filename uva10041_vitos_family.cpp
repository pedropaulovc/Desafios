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

vector<int> familias;
int qtd_familias;

int calcular_soma_distancias(int origem){
	int soma = 0;
	
	f(i, 0, familias.size()){
		soma += abs(familias[i] - origem);
	}
	
	return soma;
}

int main(){
	int qtd_testes;
	cin >> qtd_testes;
	
	int familia;
	f(i, 0, qtd_testes){
		cin >> qtd_familias;
		
		familias.clear();
		f(j, 0, qtd_familias){
			cin >> familia;
			familias.push_back(familia);
		}
		
		sort(familias.begin(), familias.end());
		
		int dist_n2_piso = calcular_soma_distancias(familias[qtd_familias/2]);
		int dist_n2_teto = calcular_soma_distancias(familias[ceil(1.0 * qtd_familias/2)]);
		
		if(dist_n2_piso < dist_n2_teto)
			cout << dist_n2_piso;
		else
			cout << dist_n2_teto;
		
		cout << endl;
	}
	
	
	return 0;
}


