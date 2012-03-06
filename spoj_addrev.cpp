/*
 * addrev.cpp
 *
 *  Created on: Feb 7, 2012
 *      Author: pedropaulovc
 */

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

long long int reverte(long long int n) {
	stringstream ss;
	ss << n;
	string num = ss.str();
	ss.str("");

	for (long long int i = num.length() - 1; i >= 0; i--) {
		ss << num[i];
	}

	long long int rev;
	ss >> rev;
	return rev;
}

int main_addrev(int argc, char **argv) {
	int casos;
	cin >> casos;

	long long int n1, n2;
	for(int i = 0; i < casos; i++){
		cin >> n1 >> n2;

		cout << reverte(reverte(n1) + reverte(n2)) << endl;
	}

	return 0;
}

