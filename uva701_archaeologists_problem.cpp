/*
 * 701-archaeologistsProblem.cpp
 *
 *  Created on: Feb 13, 2012
 *      Author: pedropaulovc
 */

#include<iostream>
#include<cmath>

using namespace std;

/**
 * Seja P o prefixo fornecido, T o número de dígitos perdidos.
 * Buscamos um N tal que o prefixo de 2^N é P.
 * Ainda, é informado que há estritamente menos digitos fornecidos que
 * o número de dígitos perdidos, logo:
 *
 * P < 10^(T - 1)
 * log10(P) < T - 1
 * T > log10(P) + 1
 *
 * Como T é inteiro:
 * T > floor(log10(P) + 1)
 * T > floor(log10(P)) + 1
 * T >= floor(log10(P)) + 2
 *
 * Ex. P = 100, T > log10(100) + 1
 *              T > 2 + 1
 *              T >= floor(2) + 2
 *              T >= 4
 *
 *     P = 999, T > log10(999) + 1
 *              T > 2,99 + 1
 *              T >= floor(2,99) + 2
 *              T >= 4
 *
 * Para um dado T, o intervalo que define números com o mesmo prefixo é:
 * P * 10^T <= X < (P + 1) * 10^T
 *
 * Para o problema proposto X = 2^N. Logo,
 *
 * P * 10^T <= X < (P + 1) * 10^T
 * P * 10^T <= 2^N < (P + 1) * 10^T
 * log2(P * 10^T) <= log2(2^N) < log2((P + 1) * 10^T)
 * log2(P) + T * log2(10) <= N < log2(P + 1) + T * log2(10)
 *
 * Como N também é inteiro, temos:
 *
 * ceil(log2(P) + T * log2(10)) <= N <= floor(log2(P + 1) + T * log2(10))
 *
 * O menor N que satisfaz o problema é dado pela primeira vez que
 *
 * ceil(log2(P) + T * log2(10)) = floor(log2(P + 1) + T * log2(10))
 *
 * Através de força bruta, testamos valores para T >= floor(log10(P)) + 2
 * sucessivamente maiores até que a igualdade seja satisfeita, determinando o N
 * buscado.
 */

long long menor_pot2_com_prefixo(long double P) {
	long double log2_P, log2_P1, log2_10, T;

	log2_P = log2(P);
	log2_P1 = log2(P + 1);
	log2_10 = log2(10);
	T = floor(log10(P)) + 2;

	while(ceil(log2_P + T * log2_10) != floor(log2_P1 + T * log2_10))
		T++;

	return (long long) ceil(log2_P + T * log2_10);

}

int main_701() {
	long double P;
	while (cin >> P)
		cout << menor_pot2_com_prefixo(P) << endl;

	return 0;
}
