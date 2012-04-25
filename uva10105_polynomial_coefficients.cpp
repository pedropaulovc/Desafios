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

#define MAX_N 12

int n, k;
vector<int> expoentes;
int fatoriais[MAX_N + 1];

int fatorial(int n){
	if(n == 0)
		return 1;	
	
	int fat = 1;
	
	f(i, 2, n + 1){
		fat *= i;
	}
	
	return fat;
}

int calcular_coeficiente(){
	int coeficiente = fatoriais[n];
	
	f(i, 0, expoentes.size()){
		coeficiente /= fatoriais[expoentes[i]];
	}
	
	return coeficiente;
}

int main(){
	int expoente;
	
	f(i, 0, MAX_N + 1){
		fatoriais[i] = fatorial(i);
	}
	
	while(cin >> n >> k){
		expoentes.clear();
		f(i, 0, k){
			cin >> expoente;
			if(expoente != 0)
				expoentes.pb(expoente);
		}
		
		cout << calcular_coeficiente() << endl;
	}
	
	return 0;
}
