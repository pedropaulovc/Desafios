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

#define MAX_N 3
#define MAX_N_QUAD MAX_N * MAX_N

int tabuleiro[MAX_N_QUAD][MAX_N_QUAD];
bool linha[MAX_N_QUAD][MAX_N_QUAD + 1];
bool coluna[MAX_N_QUAD][MAX_N_QUAD + 1];
bool quadrado[MAX_N_QUAD][MAX_N_QUAD + 1];
int n, n_quad;

void imprimir_resposta(){
	f(i, 0, n_quad){
		f(j, 0, n_quad - 1){
			cout << tabuleiro[i][j] << " ";
		}
		cout << tabuleiro[i][n_quad - 1] << endl;
	}
}

bool resolver_sudoku(int i, int j){
	if(j >= n_quad)
		return resolver_sudoku(i + 1, 0);
	if(i >= n_quad)
		return true;
	if(tabuleiro[i][j] != 0)
		return resolver_sudoku(i, j + 1);
	
	f(cand, 1, n_quad + 1){
		if(linha[i][cand] && 
			coluna[j][cand] &&
			quadrado[n*(i/n) + j/n][cand]){
			
			tabuleiro[i][j] = cand;
			linha[i][cand] = coluna[j][cand] = quadrado[n*(i/n) + j/n][cand] = false;

			debug(imprimir_resposta(); cout << endl;)

			if(resolver_sudoku(i, j + 1))
				return true;
			tabuleiro[i][j] = 0;
			linha[i][cand] = coluna[j][cand] = quadrado[n*(i/n) + j/n][cand] = true;	
		}
	}
	
	return false;
}

int main(){
	int num;
	bool primeiro = true;
	
	while(cin >> n){
		if(!primeiro)
			cout << endl;
		primeiro = false;
		
		n_quad = n * n;
		
		f(i, 0, n_quad)
			f(j, 0, n_quad + 1)
				linha[i][j] = coluna[i][j] = quadrado[i][j] = true;

		f(i, 0, n_quad){
			f(j, 0, n_quad){
				cin >> num;
				tabuleiro[i][j] = num;
				linha[i][num] = coluna[j][num] = quadrado[n*(i/n) + j/n][num] = false;
			}
		}
		
		if (resolver_sudoku(0, 0))
			imprimir_resposta();
		else
			cout << "NO SOLUTION" << endl;
	}
	return 0;
}
