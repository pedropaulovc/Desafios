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
	int ini, fim;	
} intervalo;

vector<intervalo> intervalos;
vector<intervalo> resposta;
int M;
int ini, fim;

bool compara(intervalo i1, intervalo i2){
	if(i1.ini != i2.ini)
		return i1.ini < i2.ini;
	return i1.fim > i2.fim;	
}

int main(){
	int qtd_testes;
	cin >> qtd_testes;	
		
	intervalo it;
	f(i, 0, qtd_testes){
		intervalos.clear();
		resposta.clear();
		
		cin >> M;
		while(cin >> it.ini >> it.fim) {
			if(it.ini == 0 && it.fim == 0)
				break;
			intervalos.pb(it);
		}
		
		sort(all(intervalos), compara);
		
		int escolhido;
		ini = fim = 0;
		for(int i = 0; i < intervalos.size(); i++){
			escolhido = -1;
			for(; i < intervalos.size() && intervalos[i].ini <= ini; i++){
				if(intervalos[i].fim > fim){
					fim = intervalos[i].fim;
					escolhido = i;
				}
			}
			
			if(escolhido == -1)
				break;
				
			resposta.pb(intervalos[escolhido]);
			ini = fim;
			if(fim >= M)
				break;
			
			//Tivemos que iterar até o primeiro intervalo que viola
			//intervalos[i].ini <= ini. Após a atualização verificamos novamente
			//se este intervalo passa a ser relevante.
			i--; 
		}
		
		if(fim < M){
			cout << "0"<< endl << endl;
			continue;
		}
		
		cout << resposta.size() << endl;
		f(i, 0, resposta.size())
			cout << resposta[i].ini << " " << resposta[i].fim << endl;
		cout << endl;
	}	
		
	return 0;
}
