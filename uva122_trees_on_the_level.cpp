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
	int info;
};

int incompleto;
int lido = 0;
bool inconsistente;
int valor_no;
string caminho;

no* novo_no(int info){
	no *novo = new no;
	novo->info = info;
	novo->esq = NULL;
	novo->dir = NULL;
	incompleto++;
	
	return novo;
}

void ler_no(){
	char c, conta = 0;
	stringstream ss;
	
	while(cin >> c && c != '(');
	while(cin >> c && c != ')'){
		ss << c;
		conta++;
	}
	
	valor_no = -1;	
	caminho = "";
	if(conta)
		ss >> valor_no >> c >> caminho;
	debug(cout << "'" << valor_no << " " << caminho << "'" << endl);
}

no *ler_arvore(){
	int info;
	char direcao;
	
	incompleto = 0;
	inconsistente = false;
	no *raiz = novo_no(-1);
	no *atual;
	
	while(valor_no != -1){
		atual = raiz;
		
		f(i, 0, caminho.length()){
			if(caminho[i] == 'L'){
				if(atual->esq == NULL)
					atual->esq = novo_no(-1);
				atual = atual->esq;
			} else {
				if(atual->dir == NULL)
					atual->dir = novo_no(-1);
				atual = atual->dir;
			}
		}
		if(atual->info == -1)
			incompleto--;
		else
			inconsistente = true;

		atual->info = valor_no;
		
		ler_no();
	}
	
	return raiz;
}

void preordem(no *arvore){
	cout << arvore->info << " ";
	if(arvore->esq)
		preordem(arvore->esq);
	if(arvore->dir)
		preordem(arvore->dir);
}

void imprimir_arvore(no *arvore){
	queue<no*> fila_impressao;
	vector<int> resultado;
	
	fila_impressao.push(arvore);
	
	no *atual;
	do {
		atual = fila_impressao.front();
		fila_impressao.pop();
		
		resultado.push_back(atual->info);
		if(atual->esq != NULL)
			fila_impressao.push(atual->esq);
		if(atual->dir != NULL)
			fila_impressao.push(atual->dir);
	} while(fila_impressao.size() > 0);
	
	f(i, 0, resultado.size() - 1)
		cout << resultado[i] << " ";
	cout << resultado[resultado.size() - 1];
}

int main(){
	ler_no();
	while(cin.good()){
		no *arvore = ler_arvore();
		
		if(!incompleto && !inconsistente)
			imprimir_arvore(arvore);
		else
			cout << "not complete";
		cout << endl;
		
		ler_no();
	}
	
	return 0;
}
