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
	int x, y;
} willi_maja;

willi_maja mapa[100010];

#define N 0 
#define NE 1
#define SE 2
#define S 3
#define SO 4
#define NO 5

void atualiza_xy(int &x, int &y, int direcao){

}

void gerar_mapa(){
	int ciclo = 0, tam_ciclo = 6, x = 0, y = 1, tam_direcao = 1;
	int conta_direcao = 0, direcao = SO;
	
	mapa[1].x = 0; mapa[1].y = 0;
	
	f(i, 2, 100010){
		mapa[i].x = x;
		mapa[i].y = y;
		
		ciclo++;		
		if(ciclo == tam_ciclo){
			ciclo = 0;
			tam_ciclo += 6;
			y++;
			tam_direcao++;
			direcao = SO;
			conta_direcao = 0;
			continue;
		}
		
		conta_direcao++;
		if(conta_direcao == tam_direcao){
			conta_direcao = 0;
			direcao = (direcao + 1) % 6;
		}
		
		switch(direcao){
		case N:
			y--;
			break;
		case S:
			y++;
			break;
		case NE:
			x++;
			y--;
			break;
		case NO:
			x--;
			break;
		case SE:
			x++;
			break;
		case SO:
			x--;
			y++;
			break;
		}
	}
}

int main(){
	gerar_mapa();
	
	int w;
	while(cin >> w)
		cout << mapa[w].x << " " << mapa[w].y << endl;
}
