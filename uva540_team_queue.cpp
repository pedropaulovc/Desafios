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
#define round(x) x <= 0.5 ? floor(x) : ceil(x)
#ifdef DEBUG
#define debug(x) x
#else
#define debug(x)
#endif
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

typedef struct {
	list<int> amigos;
} um_time;

um_time lista_times[1000];
map<int, int> times; //Mapeia elemento para seu time
list<int> fila;
int qtd_times;

void enfileirar(int elem){
	int time = times[elem];
	lista_times[time].amigos.push_back(elem);
	
	int tam_fila = fila.size();
	int i;
	
	if(find(fila.begin(), fila.end(), time) == fila.end())
		fila.push_back(time);
}

void desenfileirar(){
	if(fila.size() == 0)
		return;
		
	int id_time = fila.front();
	int sai = lista_times[id_time].amigos.front();
	lista_times[id_time].amigos.pop_front();
	
	cout << sai << endl;
	
	if(lista_times[id_time].amigos.size() == 0)
		fila.pop_front();
}

void processar_comandos(){
	string comando;
	int elem;
	
	getline(cin, comando);
	while(comando[0] != 'S'){
		elem = atoi(comando.c_str() + 8);
		
		if(comando[0] == 'E')
			enfileirar(elem);
		else 
			desenfileirar();
			
		getline(cin, comando);
	}
}

void popular_times(){
	int tam_time, elemento;

	for(int time = 0; time < qtd_times; time++){
		cin >> tam_time;
		for(int i = 0; i < tam_time; i++){
			cin >> elemento;
			times[elemento] = time;
		}
	}
	getchar();
}

int main(){
	int cenario = 1;	
	
	while(cin >> qtd_times && qtd_times){
		cout << "Scenario #" << cenario << endl;
		popular_times();
		processar_comandos();
		cout << endl;
		
		times.clear();
		fila.clear();
		for(int i = 0; i < qtd_times; i++)
			lista_times[i].amigos.clear();
		cenario++;
	}
	
	return 0;
}
