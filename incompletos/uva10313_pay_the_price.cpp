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

int N, L1, L2;
ll pd[301][301][301];

//qtd_moedas é a quantidade máxima de moedas que pode ser utilizada
//valor é o valor objetivo
//valor_ant é o valor da última moeda utilizada. O algoritmo calcula as possibilidades
//indo em valores decrescentes de moeda para evitar repetições.
ll solve(int qtd_moedas, int valor, int valor_ant){
	if(valor < 0 || qtd_moedas < 0 || valor_ant < 0)
		return 0;
	if(valor == 0)
		return 1;
	if(qtd_moedas == 0)
		return 0;
	if(pd[qtd_moedas][valor][valor_ant] != -1)
		return pd[qtd_moedas][valor][valor_ant];
	
	ll resposta = 0;
	for(int i = 1; i <= valor && i <= valor_ant; i++){
		resposta += solve(qtd_moedas - 1, valor - i, i);
	}
	
	pd[qtd_moedas][valor][valor_ant] = resposta;
	return resposta;
}

int main(){
	char linha[2000];

	for(int i = 0; i < 301; i++)
		for(int j = 0; j < 301; j++)
			for(int k = 0; k < 301; k++)
				pd[i][j][k] = -1;
		
	while(gets(linha)){
		L1 = L2 = -1;
	
		int contagem = sscanf(linha,"%d%d%d", &N,&L1,&L2);
		
		L1 = min(L1, 300);
		L2 = min(L2, 300);
		
		if(contagem == 3)
			printf("%lld\n", solve(L2, N, 300) - solve(L1 - 1, N, 300));
		else if(contagem == 2)
			printf("%lld\n", solve(L1, N, 300));
		else if(contagem == 1)
			printf("%lld\n", solve(300, N, 300));
	}
	return 0;
}


