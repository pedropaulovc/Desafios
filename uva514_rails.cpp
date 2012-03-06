/*
 * 514-rails.cpp
 *
 *  Created on: Feb 14, 2012
 *      Author: pedropaulovc
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool eh_permutacao_pilha(int n, int permutacao[]) {
	stack<int> pilha;
	int empilhados = 0;
	int atual = 0;
	bool loop = false;

	while (empilhados < n && !loop) {
		loop = true;
		while (permutacao[atual] > empilhados) {
			pilha.push(++empilhados);
			loop = false;
		}

		while (!pilha.empty() && permutacao[atual] == pilha.top()){
			pilha.pop();
			atual++;
			loop = false;
		}
	}

	if(!pilha.empty())
		return false;
	return true;
}

int main_514() {
	int tam_trem;
	int permutacao[1000];

	cin >> tam_trem;
	while (tam_trem > 0) {

		cin >> permutacao[0];
		while (permutacao[0] != 0) {
			for (int i = 1; i < tam_trem; i++)
				cin >> permutacao[i];

			if (eh_permutacao_pilha(tam_trem, permutacao))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;

			cin >> permutacao[0];
		}
		cout << endl;

		cin >> tam_trem;
	}

	return 0;
}

