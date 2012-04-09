#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<list>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++ )
#define FORV(it,A) for(vector<int>::iterator it = A.begin(); it!= A.end(); it++)
#define FORS(it,A) for(set<int>::iterator it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
#ifdef DEBUG
#define debug(x) x
#else
#define debug(x)
#endif
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

list<int> somas;
vector<int> numeros;
int qtd_somas;

void tentar_obter_numeros(int primeiro){
	numeros.clear();
	numeros.pb(primeiro);
	list<int> somas_tmp(somas);
	debug(cout << somas_tmp.size() << endl);
	
	int soma_atual, num_atual;
	list<int>::iterator it;
	while(somas_tmp.size() > 0){
		soma_atual = somas_tmp.front();
		num_atual = soma_atual - primeiro;
		
		debug(
			f(i, 0, numeros.size())
				cout << numeros[i] << " ";
			cout << " / ";
			for (it=somas_tmp.begin() ; it != somas_tmp.end(); it++ )
				cout << *it << " ";
			cout << "/ " << soma_atual << " / " << num_atual;
			cout << endl;
		)


		f(i, 0, numeros.size()){
			it = find(somas_tmp.begin(), somas_tmp.end(), num_atual + numeros[i]);
			if(it == somas_tmp.end()){
				numeros.clear();
				return;
			}
			
			somas_tmp.erase(it);
		}
		
		numeros.pb(num_atual);
	}
}

void obter_numeros(){
	somas.sort();
	int primeiro = min(somas.front(), -1);
	
	do {
		primeiro++;
		tentar_obter_numeros(primeiro);
	} while(numeros.size() == 0 && primeiro < somas.front()/2);
}

int main(){	
	int soma;
	stringstream ss;
	string linha;
	
	while(getline(cin, linha)){
		somas.clear();
		numeros.clear();
		ss.clear();
		
		ss << linha;
		ss >> qtd_somas;
		while(ss >> soma){
			somas.pb(soma);	
		}

		obter_numeros();
		
		int n = numeros.size();
		if(n == 0 || somas.size() != n * (n - 1)/2){
			cout << "Impossible" << endl;
			continue;
		}
		
		f(i, 0, numeros.size() - 1)
			cout << numeros[i] << " ";
		cout << numeros[numeros.size() - 1] << endl;
	}
	
	return 0;
}
