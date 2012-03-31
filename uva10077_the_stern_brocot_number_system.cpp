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

typedef struct {
	int num, den;
} fracao;

typedef struct {
	fracao esq, atual, dir;
} numero;

bool operator< (fracao f1, fracao f2){
	return f1.num * f2.den - f2.num * f1.den < 0;
}

bool operator> (fracao f1, fracao f2){
	return f1.num * f2.den - f2.num * f1.den > 0;
}

bool operator!= (fracao f1, fracao f2){
	return f1.num != f2.num || f1.den != f2.den;
}

void calcular_representacao(fracao frac){
	numero iter;
	iter.esq.num = 0;
	iter.esq.den = 1;
	iter.atual.num = 1;
	iter.atual.den = 1;
	iter.dir.num = 1;
	iter.dir.den = 0;
	
	debug(cout << frac.num << " " << frac.den << endl);
	
	while(frac != iter.atual){
		debug(cout << "diferente" << endl);
		if(frac < iter.atual){
			iter.dir.num = iter.atual.num;
			iter.dir.den = iter.atual.den;

			iter.atual.num += iter.esq.num;
			iter.atual.den += iter.esq.den;
			
			cout << "L";
		} else {
			iter.esq.num = iter.atual.num;
			iter.esq.den = iter.atual.den;

			iter.atual.num += iter.dir.num;
			iter.atual.den += iter.dir.den;
			
			cout << "R";
		}
	}
	
	cout << endl;
}

int main(){
	fracao frac;
	
	while(cin >> frac.num >> frac.den && !(frac.num == 1 && frac.den == 1)){
		calcular_representacao(frac);
	}

	return 0;
}

