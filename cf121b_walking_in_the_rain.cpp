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

vector<int> pos_validade(1001);
vector<vector<int> > validade_pos(1001);

int main(){
	int qtd_ladrilhos;
	cin >> qtd_ladrilhos;
	
	f(i, 0, qtd_ladrilhos){
		cin >> pos_validade[i];
		validade_pos[pos_validade[i]].pb(i);
	}

	int tempo = 1;
	list<int>::iterator it; 
	int atual;
	while(true){
		f(i, 0, validade_pos[tempo].size()){
			atual = validade_pos[tempo][i];
			pos_validade[atual] = -1;
			if(atual == 0 || atual == qtd_ladrilhos - 1 || 
				pos_validade[atual + 1] == -1 || pos_validade[atual - 1] == -1) {
					cout << tempo << endl;
					return 0;
				}
		}
		tempo++;	
	}
	
	return 0;
}
