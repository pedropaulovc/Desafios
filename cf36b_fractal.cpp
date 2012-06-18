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
#include<fstream>
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

char fractal[250][250];
char padrao[5][5];
int n, k;

void pinta(int posi, int posj, int fator){
	f(i, posi, posi + fator)
		f(j, posj, posj + fator)	
			fractal[i][j] = '*';
}

void gera_fractal(int pi, int pj, int fator, int it){
	if(it < 0)
		return;

	f(i, 0, n){
		int posi = pi + fator * i;
	
		f(j, 0, n){
			int posj = pj + fator * j;
		
			if(padrao[i][j] == '*')
				pinta(posi, posj, fator); 
			else
				gera_fractal(posi, posj, fator/n, it - 1);
		}
	}
}

int main(){
	ifstream ent;
	ent.open("input.txt", ios::in);
	ofstream sai;
	sai.open("output.txt", ios::out);


	ent >> n >> k;
	
	int nk = pow(n, k);
	
	f(i, 0, n)
		f(j, 0, n)
			ent >> padrao[i][j];
	
	gera_fractal(0, 0, nk/n, k); 
	
	f(i, 0, nk){
		f(j, 0, nk)
			if (fractal[i][j] == '*')
				sai << '*';
			else
				sai << '.';
		sai << endl;
	}
	
	return 0;
}
