/*
 * 10219-findTheWays.cpp
 *
 *  Created on: Feb 16, 2012
 *      Author: pedropaulovc
 */


#include <iostream>

using namespace std;

int combinacao(int n, int k){
	double comb = 1.0;

	while(k > 0){
		comb *= n;
		comb /= k;
		n--;
		k--;
	}

	return (int) comb;
}

int main_10219(){
	int n, k;
	while(cin >> n >> k)
		cout << combinacao(n, k);

}

