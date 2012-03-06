/*
 * 612-dnaSorting.cpp
 *
 *  Created on: Feb 14, 2012
 *      Author: pedropaulovc
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
	int inversoes;
	int pos;
} item;

int calcula_inversoes(string sequencia) {
	int len = sequencia.length();
	int inversoes = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (sequencia[i] > sequencia[j])
				inversoes++;
		}
	}

	return inversoes;
}

bool menor_num_inversoes(item it1, item it2) {
	return it1.inversoes < it2.inversoes;
}

void tratar_dataset() {
	int qtd_string, tam_string;
	string dataset[100];
	vector<item> lista_inversoes;
	item novo;

	cin >> tam_string >> qtd_string;

	for (int i = 0; i < qtd_string; i++) {
		cin >> dataset[i];

		novo.pos = i;
		novo.inversoes = calcula_inversoes(dataset[i]);

		lista_inversoes.push_back(novo);
	}

	stable_sort(lista_inversoes.begin(), lista_inversoes.end(),
			menor_num_inversoes);

	for (int i = 0; i < qtd_string; i++) {
		cout << dataset[lista_inversoes[i].pos] << endl;
	}
}

int main_612() {
	int num_datasets;
	cin >> num_datasets;

	for (int i = 0; i < num_datasets - 1; i++) {
		tratar_dataset();
		cout << endl;
	}

	tratar_dataset();

	return 0;
}
