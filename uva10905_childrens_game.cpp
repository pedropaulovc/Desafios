/*
 * 10905-childrensGame.cpp
 *
 *  Created on: Feb 19, 2012
 *      Author: pedropaulovc
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool calcular_mais_significativo(string a, string b){
	int minimo = min(a.length(), b.length());
	for(int i = 0; i < minimo; i++)
		if(a[i] != b[i])
			return a < b;

	return (a + b) < (b + a);
}

void calcular_maior_numero(int tam_entrada) {
	string num;
	vector<string> numeros;

	for (int i = 0; i < tam_entrada; i++) {
		cin >> num;
		numeros.push_back(num);
	}

	sort(numeros.begin(), numeros.end(), calcular_mais_significativo);

	for (int i = tam_entrada - 1; i >= 0; i--) {
		cout << numeros[i];
	}
}

int main_10905() {
	int tam_entrada;

	cin >> tam_entrada;
	calcular_maior_numero(tam_entrada);
	while (tam_entrada != 0) {
		cin >> tam_entrada;
		cout << endl;
		calcular_maior_numero(tam_entrada);
	}

	return 0;

}
