/*
 * 10377-mazeTraversal.cpp
 *
 *  Created on: Feb 19, 2012
 *      Author: pedropaulovc
 */

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

char obter_prox_r(char atual) {
	switch (atual) {
	case 'N':
		return 'E';
	case 'E':
		return 'S';
	case 'S':
		return 'W';
	case 'W':
		return 'N';
	}
	return 0;
}

char obter_prox_l(char atual) {
	switch (atual) {
	case 'N':
		return 'W';
	case 'E':
		return 'N';
	case 'S':
		return 'E';
	case 'W':
		return 'S';
	}
	return 0;
}

void simular_movimentos(int l, int c, char tab[60][60]) {
	int i, j;
	char comando, orientacao = 'N';

	cin >> i >> j;
	i--;
	j--;

	comando = getchar();
	while (comando != 'Q') {
		switch (comando) {
		case 'R':
			orientacao = obter_prox_r(orientacao);
			break;
		case 'L':
			orientacao = obter_prox_l(orientacao);
			break;
		case 'F':
			if (orientacao == 'N' && i > 0 && tab[i - 1][j] == ' ')
				i--;
			else if (orientacao == 'E' && j < c - 2 && tab[i][j + 1] == ' ')
				j++;
			else if (orientacao == 'S' && i < l - 2 && tab[i + 1][j] == ' ')
				i++;
			else if (orientacao == 'W' && j > 0 && tab[i][j - 1] == ' ')
				j--;
			break;
		default:
			break;
		}

		comando = getchar();
	}

	cout << i + 1 << " " << j + 1 << " " << orientacao << endl;
}

void ler_tabuleiro(int l, int c, char tab[60][60]) {
	getchar();
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++)
			tab[i][j] = getchar();
		getchar();
	}
}

int main_10377() {
	char tab[60][60];
	int num_tab, l, c;

	cin >> num_tab;
	for (int i = 0; i < num_tab; i++) {
		cin >> l >> c;
		ler_tabuleiro(l, c, tab);
		simular_movimentos(l, c, tab);
		if (i != num_tab - 1)
			cout << endl;
	}

	return 0;
}

