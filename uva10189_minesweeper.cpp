/*
 * 10189-minesweeper.cpp
 *
 *  Created on: Feb 15, 2012
 *      Author: pedropaulovc
 */

#include <string>
#include <iostream>
#include <cstdio>

/**
 * Tabuleiro tem duas posições a mais para evitar bound check.
 */
#define MAX_TAB 102

using namespace std;

void ler_tabuleiro(int lin, int col, char tab[MAX_TAB][MAX_TAB]) {
	char atual;
	for (int i = 1; i < lin + 1; i++) {
		for (int j = 1; j < col + 1; j++) {
			do {
				atual = getchar();
			} while (atual != '.' && atual != '*');
			if (atual == '.')
				atual = '0';
			tab[i][j] = atual;
		}
	}
}

void inserir_mina(int i, int j, int lin, int col, char tab[MAX_TAB][MAX_TAB]) {
	if (tab[i - 1][j - 1] != '*')
		tab[i - 1][j - 1]++;
	if (tab[i - 1][j] != '*')
		tab[i - 1][j]++;
	if (tab[i - 1][j + 1] != '*')
		tab[i - 1][j + 1]++;
	if (tab[i][j - 1] != '*')
		tab[i][j - 1]++;
	if (tab[i][j + 1] != '*')
		tab[i][j + 1]++;
	if (tab[i + 1][j - 1] != '*')
		tab[i + 1][j - 1]++;
	if (tab[i + 1][j] != '*')
		tab[i + 1][j]++;
	if (tab[i + 1][j + 1] != '*')
		tab[i + 1][j + 1]++;
}

void resolver_tabuleiro(int lin, int col, char tab[MAX_TAB][MAX_TAB]) {
	for (int i = 1; i < lin + 1; i++) {
		for (int j = 1; j < col + 1; j++) {
			if (tab[i][j] == '*')
				inserir_mina(i, j, lin, col, tab);
		}
	}
}

void imprimir_tabuleiro(int lin, int col, char tab[MAX_TAB][MAX_TAB]) {
	for (int i = 1; i < lin + 1; i++) {
		for (int j = 1; j < col + 1; j++) {
			cout << tab[i][j];
		}
		cout << endl;
	}
}

int main_10189() {
	int lin, col, i = 1;
	char tab[102][102];

	cin >> lin >> col;
	while (lin != 0 && col != 0) {
		cout << "Field #" << i << ":" << endl;
		ler_tabuleiro(lin, col, tab);
		resolver_tabuleiro(lin, col, tab);
		imprimir_tabuleiro(lin, col, tab);
		i++;

		cin >> lin >> col;
		if(lin != 0 && col != 0)
			cout << endl;
	}

	return 0;
}

