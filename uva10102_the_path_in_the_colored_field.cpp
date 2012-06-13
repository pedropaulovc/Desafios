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

#define MAX_LADO 200

typedef struct {
	int x, y;
} pos;

char mapa[MAX_LADO + 1][MAX_LADO + 1];
int tam_mapa;
vector<pos> um, tres;

int calcular_distancia(){
	vector<int> distancia;
	int dist, nova_dist;
	
	f(i, 0, um.size()){
		dist = MAX_LADO + 1;
		f(j, 0, tres.size()){
			nova_dist = abs(um[i].x - tres[j].x) + abs(um[i].y - tres[j].y);
			if(nova_dist < dist)
				dist = nova_dist;
		}
		distancia.pb(dist);
	}
	
	return *max_element(distancia.begin(), distancia.end());
}

int main(){
	pos posicao;

	while(cin >> tam_mapa){
		um.clear();
		tres.clear();
		f(i, 0, tam_mapa)
			f(j, 0, tam_mapa){
				cin >> mapa[i][j];
				
				posicao.x = i;
				posicao.y = j;
				if(mapa[i][j] == '1')
					um.pb(posicao);
				else if(mapa[i][j] == '3')
					tres.pb(posicao);
			}
		
		cout << calcular_distancia() << endl;
	}
	
	return 0;
}
