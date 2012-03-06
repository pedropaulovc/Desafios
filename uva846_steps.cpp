/*
 * 846-steps.cpp
 *
 *  Created on: Feb 14, 2012
 *      Author: pedropaulovc
 */

#include <iostream>

using namespace std;

/**
 * Passos         | Inc. tam. passo | Qtd. passos | Dist. percorrida
 * 0              |                 | 0           | 0
 * 1              |  + 1            | 1           | 1
 * 1 1            |  + 1            | 2           | 2
 * 1 2 1          |  + 2            | 3           | 4
 * 1 2 2 1        |  + 2            | 4           | 6
 * 1 2 3 2 1      |  + 3            | 5           | 9
 * 1 2 3 3 2 1    |  + 4            | 6           | 12
 * 1 2 3 4 3 2 1  |  + 5            | 7           | 16
 */

int calcular_passos(int origem, int destino) {
	int passos = 0;
	int	distancia = destino - origem;
	int tam_passo = 1;

	while(distancia > 0){
		passos++;
		distancia -= tam_passo;

		if(distancia <= 0)
			return passos;

		passos++;
		distancia -= tam_passo;

		tam_passo++;
	}

	return passos;
}

int main_846() {
	int num_testes, origem, destino;

	cin >> num_testes;

	for (int i = 0; i < num_testes; i++) {
		cin >> origem >> destino;
		cout << calcular_passos(origem, destino) << endl;
	}

	return 0;
}
