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

ll capacidade_robo;
ll pilha[1000001];
ll topo = 0;

void inverter_pilha(){
	if(topo <= 1) //0 ou 1 elementos
		return;
	int qtd_swaps = min(capacidade_robo, topo);
	
	int tmp;
	for(int sup = topo - 1, inf = topo - qtd_swaps; sup > inf; sup--, inf++){
		tmp = pilha[inf];
		pilha[inf] = pilha[sup];
		pilha[sup] = tmp;
	}
}

void imprimir_pilha(){
	for(int i = topo - 1; i >= 0; i--){
		printf("%d\n", pilha[i]);
	}
}

int main(){
	scanf("%d", &capacidade_robo);
	
	int atual, inverter;
	bool ler = true;
	
	scanf("%d", &atual);
	while(atual){
		switch(atual){
		case -1:
			printf("%d\n", pilha[--topo]);
			break;
		case -2:
			inverter = 0;
			while(atual == -2) {
				scanf("%d", &atual);
				inverter++;
			}
			ler = false;
			if(inverter % 2)
				inverter_pilha();
			break;
		case -3:
			imprimir_pilha();
			break;
		default:
			pilha[topo++] = atual;
			break;
		}
		
		if(ler)
			scanf("%d", &atual);
		ler = true;
	}
	
	return 0;
}
