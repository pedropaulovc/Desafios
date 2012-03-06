/*
 * addrev.cpp
 *
 *  Created on: Feb 7, 2012
 *      Author: pedropaulovc
 */

#include <cstdio>

using namespace std;

int main_458(int argc, char **argv) {
	int letra;

	while((letra = getchar()) != EOF){
		if(letra < 32)
			putchar(letra);
		else
			putchar(letra - 7);
	}

	return 0;
}
