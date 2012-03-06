/*
 * 112-treeSumming.cpp
 *
 *  Created on: Feb 12, 2012
 *      Author: pedropaulovc
 */

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define PROXIMO_CHAR do { atual = getchar();	} while(atual == ' ' || atual == '\n');
#define NUM 1
#define ABRE_PAR 2
#define FECHA_PAR 3
#define DESCONHECIDO 4
char string_num_lido[32];
int num_lido;

typedef struct no {
	int info;
	struct no *esq;
	struct no *dir;
} no;

int ler_proximo_item_lexico() {
	int atual;

	PROXIMO_CHAR

	if (atual == EOF
	)
		return EOF;

	int i = 0;
	bool leu_num = false;
	while ((atual >= '0' && atual <= '9') || atual == '-') {
		string_num_lido[i] = (char) atual;
		PROXIMO_CHAR
		leu_num = true;
		i++;
	}
	string_num_lido[i] = '\0';
	num_lido = atoi(string_num_lido);

	if (leu_num) {
		ungetc(atual, stdin);
		return NUM;
	}

	if (atual == '(')
		return ABRE_PAR;
	if (atual == ')')
		return FECHA_PAR;

	return DESCONHECIDO;
}

no* ler_entrada() {
	no *atual = NULL;
	int ilc;

	ilc = ler_proximo_item_lexico();
	if (ilc != ABRE_PAR) {
		cerr << "Esperava ABRE_PAR, recebeu " << ilc << endl;
	}

	ilc = ler_proximo_item_lexico();
	switch (ilc) {
	case FECHA_PAR:
		break;
	case NUM:
		atual = new no();
		atual->info = num_lido;
		atual->esq = ler_entrada();
		atual->dir = ler_entrada();

		ilc = ler_proximo_item_lexico();
		if (ilc != FECHA_PAR) {
			cerr << "Esperava FECHA_PAR, recebeu " << ilc << endl;
		}
		break;
	default:
		cerr << "Recebeu " << ilc << " inesperado." << endl;
		break;
	}

	return atual;
}

void preordem(no *arvore){
	if(arvore == NULL)
		return;
	cout << arvore->info << " ";
	preordem(arvore->esq);
	preordem(arvore->dir);
}

void inordem(no *arvore){
	if(arvore == NULL)
		return;
	inordem(arvore->esq);
	cout << arvore->info << " ";
	inordem(arvore->dir);
}

void posordem(no *arvore, int num_tabs){
	if(arvore == NULL)
		return;
	posordem(arvore->dir, num_tabs + 1);
	for(int i = 0; i < num_tabs; i++)
		cout << "    ";
	cout << arvore->info << endl;;
	posordem(arvore->esq, num_tabs + 1);
}

void limpa_arvore(no *arvore){
	if(arvore == NULL)
		return;
	limpa_arvore(arvore->esq);
	limpa_arvore(arvore->dir);
	delete arvore;
}

bool busca_soma_dfs(int soma, int atual, no *arvore){
	if(arvore == NULL)
		return false;
	atual += arvore->info;
	if(arvore->esq == NULL && arvore->dir == NULL)
		return soma == atual;
//	cout << "soma = " << soma << "; atual = " << atual << "; nó = " << arvore->info << endl;
	if(busca_soma_dfs(soma, atual, arvore->esq))
		return true;
	return busca_soma_dfs(soma, atual, arvore->dir);
}

int main_112(int argc, char **argv) {
	int ilc;
	int soma;
	no *arvore;
	while ((ilc = ler_proximo_item_lexico()) != EOF) {
		soma = num_lido;
		arvore = ler_entrada();

//		posordem(arvore, 0);

		if(busca_soma_dfs(soma, 0, arvore))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		limpa_arvore(arvore);
	}

	return 0;
}

