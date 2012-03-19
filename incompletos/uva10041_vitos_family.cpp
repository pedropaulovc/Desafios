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

#define MAX_PARENTES 30000
int parentes[MAX_PARENTES];

int main(){
	int qtd_testes, qtd_parentes, parente;
	int distancia_piso, distancia_teto;
	double centro_massa_piso, centro_massa_teto;
	cin >> qtd_testes;
	
	f(i, 0, qtd_testes){
		memset(parentes, 0, MAX_PARENTES);
		cin >> qtd_parentes;
		f(j, 0, qtd_parentes){
			cin >> parente;
			parentes[parente]++;
		}
		
		centro_massa_piso = centro_massa_teto = 0;
		f(j, 0, MAX_PARENTES){
			centro_massa_piso += parentes[j] * j;
		}
		
		centro_massa_teto = centro_massa_piso;
		centro_massa_piso = floor(centro_massa_piso / qtd_parentes);
		centro_massa_teto = ceil(centro_massa_teto / qtd_parentes);

		debug(cout << "cmp = " << centro_massa_piso << endl;)
		debug(cout << "cmt = " << centro_massa_teto << endl;)
		distancia_piso =  distancia_teto = 0;
		f(j, 0, MAX_PARENTES){
			distancia_piso += abs(centro_massa_piso - j) * parentes[j];
			distancia_teto += abs(centro_massa_teto - j) * parentes[j];
		}
		
		cout << min(distancia_piso, distancia_teto);
	}	
	
	return 0;
}


