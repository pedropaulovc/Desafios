/*
 * 120-stacksOfFlapjacks.cpp
 *
 *  Created on: Feb 20, 2012
 *      Author: pedropaulovc
 */

#include <queue>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int obter_pos_maior(deque<int> pilha, int inicio, int fim) {
	int pos_maior = inicio;
	int maior = pilha[inicio];

	for (int i = 0; i < fim; i++)
		if (pilha[i] > maior) {
			pos_maior = i;
			maior = pilha[i];
		}

	return pos_maior;
}

void imprimir_pilha(deque<int> pilha) {
	for (unsigned int i = 0; i < pilha.size(); i++) {
		cout << pilha[i] << " ";
	}
	cout << endl;
}

bool verificar_pilha_ordenada(deque<int> pilha) {
	for (unsigned int i = 1; i < pilha.size(); i++)
		if (pilha[i - 1] > pilha[i])
			return false;
	return true;
}

void ordenar_panquecas(deque<int> pilha) {
	deque<int> temp;

	int tam_pilha = pilha.size();
	int ordenados = 0;
	while (!verificar_pilha_ordenada(pilha)) {
		int maior = obter_pos_maior(pilha, 0, tam_pilha - ordenados);

		if(tam_pilha - maior == ordenados + 1){
			ordenados++;
			continue;
		}

		if (maior != 0)
			cout << tam_pilha - maior << " ";
		for (int j = 0; j <= maior; j++) {
			temp.push_back(pilha.front());
			pilha.pop_front();
		}

		for (int j = 0; j <= maior; j++) {
			pilha.push_front(temp.front());
			temp.pop_front();
		}

		cout << ordenados + 1 << " ";

		for (int j = 0; j < tam_pilha - ordenados; j++) {
			temp.push_back(pilha.front());
			pilha.pop_front();
		}

		for (int j = 0; j < tam_pilha - ordenados; j++) {
			pilha.push_front(temp.front());
			temp.pop_front();
		}

//		imprimir_pilha(pilha);
		ordenados++;
	}

	cout << "0" << endl;
}

int main_120() {
	string linha;
	stringstream ss;
	int n;
	deque<int> pilha;

	while (getline(cin, linha).good()) {
		ss << linha << " ";

		pilha.clear();
		while (ss >> n) {
			pilha.push_back(n);
		}
		ss.clear();

		if (pilha.size() > 0) {
			cout << linha << endl;
			ordenar_panquecas(pilha);
		}

	}

	return 0;
}

