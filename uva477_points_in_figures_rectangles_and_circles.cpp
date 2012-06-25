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
	double x1, x2, y1, y2, r;
	char tipo;
} figura;

typedef struct {
	double x, y;
} ponto;

vector<figura> figuras;

void esta_contido(ponto p, int num){
	bool contido = false;
	figura f;
	f(i, 0, figuras.size()){
		f = figuras[i];
		if(f.tipo == 'r' && p.x > f.x1 && p.x < f.x2 && p.y < f.y1 && p.y > f.y2){
			contido = true;
			cout << "Point " << num << " is contained in figure " << i + 1 << endl;
		} else if(f.tipo == 'c' && sqrt(quad(p.x - f.x1) + quad(p.y - f.y1)) < f.r){
			contido = true;
			cout << "Point " << num << " is contained in figure " << i + 1 << endl;
		}
	}
	
	if(!contido)
		cout << "Point " << num << " is not contained in any figure" << endl;
}

int main(){
	figura f;
	ponto p;
	while(cin >> f.tipo && f.tipo != '*'){
		if(f.tipo == 'c'){
			cin >> f.x1 >> f.y1 >> f.r;
		} else if(f.tipo == 'r'){
			cin >> f.x1 >> f.y1 >> f.x2 >> f.y2;
		}
		figuras.pb(f);
	}
	
	int i = 1;
	while(cin >> p.x >> p.y && !(p.x == 9999.9 && p.y == 9999.9))
		esta_contido(p, i++);
	
	
	return 0;
}
