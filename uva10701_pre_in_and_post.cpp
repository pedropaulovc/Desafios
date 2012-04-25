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

typedef struct no no;
struct no {
	struct no *esq, *dir;
	char info;
};

map<char, int> ordem;
string pre, in;
int tam_arvore;

no* novo_no(char info){
	no* novo = new no;
	novo->info = info;
	novo->esq = novo->dir = NULL;
	
	return novo;
}

no* gerar_arvore(){
	no *atual, *ant, *novo;
	
	no *raiz = novo_no(pre[0]);
	
	f(i, 1, tam_arvore){
		atual = raiz;
		
		while(atual == raiz || atual != NULL){
			ant = atual;
			if(ordem[pre[i]] < ordem[atual->info])
				atual = atual->esq;
			else
				atual = atual->dir;
		}
		
		novo = novo_no(pre[i]);
		if(ordem[pre[i]] < ordem[ant->info])
			ant->esq = novo;
		else
			ant->dir = novo;
	}
	
	return raiz;
}

void posordem(no *arvore){
	if(arvore->esq != NULL)
		posordem(arvore->esq);
	if(arvore->dir != NULL)
		posordem(arvore->dir);
	cout << arvore->info;
}


int main(){
	int qtd_testes, conta_ordem;
	cin >> qtd_testes;
	
	string linha;
	f(i, 0, qtd_testes){
		conta_ordem = 0;
		ordem.clear();
		
		cin >> tam_arvore;
		getchar();
		getline(cin, pre, ' ');
		getline(cin, in);
		
		f(j, 0, tam_arvore)
			ordem[in[j]] = conta_ordem++;
		
		posordem(gerar_arvore());
		cout << endl;
	}
	
	return 0;
}
