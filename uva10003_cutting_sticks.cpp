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
#include<climits>
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

int comprimento;
int qtd_cortes;
vector<int> cortes;
int pd[53][53];

int solve (int i, int f) {
    if (i + 1 == f)
    	return 0;

    if (pd[i][f] != -1)
        return pd[i][f];

    int custo;
    int min = INT_MAX;

    for (int k = i + 1; k < f; k++) {
        custo = solve (i, k) + solve (k, f) + cortes[f] - cortes[i];
        if (custo < min) min = custo;
    }

    return pd[i][f] = min;
}


int main(){
	int corte;
	while(cin >> comprimento && comprimento > 0){
		cortes.clear();
		
		cin >> qtd_cortes;
		
		cortes.pb(0);
		f(i, 0, qtd_cortes){
			cin >> corte;
			cortes.pb(corte);
		}
		cortes.pb(comprimento);
		
		f(i, 0, 53)
			f(j, 0, 53)
				pd[i][j] = -1;
			
		
		cout << "The minimum cutting is " << 
			solve(0, qtd_cortes + 1) << "." << endl;
	}

	return 0;
}
