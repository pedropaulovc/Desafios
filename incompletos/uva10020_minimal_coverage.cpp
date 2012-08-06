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
	int i, f;
} segmento;

int qtd_testes;
int M;
vector<segmento> segmentos;

int calcula_cobertura(segmento s){
	int i = max(0, s.i);
	int f = min(M, s.f);
	
	if(f <= i)
		return 0;
	return f - i;
}

bool compara_segmentos(segmento s1, segmento s2){
	return calcula_cobertura(s1) < calcula_cobertura(s2);
}

int main(){
	segmento s;
	
	cin >> qtd_testes;
	
	f(t, 0, qtd_testes){
		cin >> M;
		while(cin >> s.i >> s.f && !(s.i == 0 && s.f == 0))
			segmentos.pb(s);
		
		sort(all(segmentos), compara_segmentos);
	}
	
	return 0;
}
