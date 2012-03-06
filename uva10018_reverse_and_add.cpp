/*
 * 10018-reverseAndAdd.cpp
 *
 *  Created on: Feb 15, 2012
 *      Author: pedropaulovc
 */

#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

unsigned long long inverter(unsigned int entrada) {
	int digito;
	unsigned long long invertido = 0;
	while (entrada > 0) {
		digito = entrada % 10;
		invertido = invertido * 10 + digito;
		entrada /= 10;
	}

	return invertido;
}

bool eh_palindromo(unsigned int entrada) {
	return (long long) entrada == inverter(entrada);
}

void calcular_palindromo(unsigned int entrada) {
	int i = 0;
	while (!eh_palindromo(entrada)) {
		entrada += inverter(entrada);
		i++;
	}
	cout << i << " " << entrada << endl;
}

int main_10018() {
	int num_testes;
	cin >> num_testes;

	unsigned int entrada;
	for (int i = 0; i < num_testes; i++) {
		cin >> entrada;
		calcular_palindromo(entrada);
	}

	return 0;
}

