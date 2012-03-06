/*
 * fctrl.cpp
 *
 *  Created on: Feb 7, 2012
 *      Author: pedropaulovc
 */

#include <iostream>

using namespace std;

long long int zeros(long long int n){
	long long int zeros = 0;
	long long int mod = n % 10;

	if(mod < 5)
		n -= mod;
	if(mod > 5)
		n -= mod - 5;

	for(long long int i = 5; i <= n; i *= 5){
		zeros += n/i;
	}

	return zeros;
}


int main_fctrl(int argc, char **argv){
	long long int testes;
	cin >> testes;

	long long int n;
	for(long long int i = 0; i < testes; i++){
		cin >> n;
		cout << zeros(n) << endl;
	}

	return 0;
}

