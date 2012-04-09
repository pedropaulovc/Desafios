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

#define MAX_N 8
#define MAX_K 64

int n, k;

void calcular_possibilidades_branco(int casas_branco[MAX_N + 1], ll possib_branco[MAX_N + 1][MAX_K + 1]){
	f(i, 1, n + 1)
		if(i % 2)
			casas_branco[i] = i;
		else
			casas_branco[i] = casas_branco[i - 1];

	f(d, 0, n + 1)
		possib_branco[d][0] = 1;
	
	
	f(b, 1, k + 1)
		possib_branco[0][b] = 0;
	
	
	for (int d = 1; d <= n; d++){
		int b = 1;
		while(b <= k && b <= d){
			possib_branco[d][b] = possib_branco[d - 1][b] +
								  possib_branco[d - 1][b - 1] * (casas_branco[d] - b + 1);
			b++;
		}
	}
}

void calcular_possibilidades_preto(int casas_preto[MAX_N + 1], ll possib_preto[MAX_N + 1][MAX_K + 1]){
	f(i, 1, n)
		if(i % 2)
			casas_preto[i] = i + 1;
		else
			casas_preto[i] = casas_preto[i-1];  
	
	f(d, 0, n){
		possib_preto[d][0] = 1;
	}
	
	f(b, 1, k + 1){
		possib_preto[0][b] = 0;
	}

	for (int d = 1; d <= n-1; d++){
		int b = 1;
		while (b <= k && b <= d){
			possib_preto[d][b] = possib_preto[d - 1][b] + 
								 possib_preto[d - 1][b - 1] * (casas_preto[d] - b + 1);
			b++;
		}
	}
}

ll calcular_qtd_possibilidades() {
	int casas_branco[MAX_N + 1];
	int casas_preto[MAX_N + 1];
	
	//possib_branco[d][b] significa a quantidade de possibilidades de colocar b bispos
	//nas primeiras d diagonais brancas.
	ll possib_branco[MAX_N + 1][MAX_K + 1] = {{0}};
	ll possib_preto[MAX_N + 1][MAX_K + 1] = {{0}};
	
	calcular_possibilidades_branco(casas_branco, possib_branco);
	calcular_possibilidades_preto(casas_preto, possib_preto);

	ll resposta = 0;
	for (int b = 0; b <= k; b++)
		resposta += possib_branco[n][b] * possib_preto[n - 1][k - b];
	
	return resposta;
}

int main() {
	while(cin >> n >> k && !(n == 0 && k == 0))
		cout << calcular_qtd_possibilidades() << endl;
	return 0;
}

