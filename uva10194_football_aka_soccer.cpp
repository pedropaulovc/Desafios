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

#define MAX_TIMES 30

typedef struct {
	string nome;
	int gols_feitos, gols_sofridos;
	int vitorias, empates, derrotas;
	int jogos_jogados, pontos;
} um_time;

string nome_torneio;
int qtd_times, qtd_partidas;
vector<um_time> times;
map<string, int> id_time;

void computar_partida(char *partida){
	int len = strlen(partida);
	char *nome1 = partida, *nome2;
	char *gols1, *gols2;
	
	int i = 0;
	while(partida[i] != '#'){
		i++;
	}
	
	partida[i] = '\0';
	gols1 = partida + i + 1;
	
	while(partida[i] != '@'){
		i++;
	}

	partida[i] = '\0';
	gols2 = partida + i + 1;
	
	while(partida[i] != '#'){
		i++;
	}
	
	partida[i] = '\0';
	nome2 = partida + i + 1;
	
	string s_nome1(nome1), s_nome2(nome2);
	
	int id_time1 = id_time[s_nome1];
	int id_time2 = id_time[s_nome2];
	
	int i_gols1 = atoi(gols1);
	int i_gols2 = atoi(gols2);
	
	times[id_time1].gols_feitos += i_gols1;
	times[id_time2].gols_sofridos += i_gols1;
	
	times[id_time1].gols_sofridos += i_gols2;
	times[id_time2].gols_feitos += i_gols2;
	
	times[id_time1].jogos_jogados++;
	times[id_time2].jogos_jogados++;
	

	if(i_gols1 == i_gols2){
		times[id_time1].empates++;
		times[id_time2].empates++;
		times[id_time1].pontos++;
		times[id_time2].pontos++;
		
		return;
	}
	
	int vencedor, perdedor;
	if(i_gols1 > i_gols2){
		vencedor = id_time1;
		perdedor = id_time2;		
	} else {
		vencedor = id_time2;
		perdedor = id_time1;
	}
	
	times[vencedor].vitorias++;
	times[perdedor].derrotas++;
	
	times[vencedor].pontos += 3;
}

bool compara_case_insensitive (char c1, char c2){
	return tolower(c1)<tolower(c2);
}

bool compara_times(um_time time1, um_time time2){
	if(time1.pontos != time2.pontos)
		return time1.pontos > time2.pontos;
	if(time1.vitorias != time2.vitorias)
		return time1.vitorias > time2.vitorias;

	int saldo1 = time1.gols_feitos - time1.gols_sofridos;
	int saldo2 = time2.gols_feitos - time2.gols_sofridos;
	
	if(saldo1 != saldo2)
		return saldo1 > saldo2;
	if(time1.gols_feitos != time2.gols_feitos)
		return time1.gols_feitos > time2.gols_feitos;
	if(time1.jogos_jogados != time2.jogos_jogados)
		return time1.jogos_jogados < time2.jogos_jogados;
	return lexicographical_compare(time1.nome.begin(), time1.nome.end(),
		time2.nome.begin(), time2.nome.end(), compara_case_insensitive);
}

void exibir_resultados(){
	sort(times.begin(), times.end(), compara_times);

	cout << nome_torneio << endl;
	for(int i = 0; i < qtd_times; i++){
		cout << i + 1 << ") " << times[i].nome << " " << times[i].pontos << "p, " << times[i].jogos_jogados  << "g ("
			<< times[i].vitorias << "-" << times[i].empates << "-" << times[i].derrotas << "), "
			<< times[i].gols_feitos - times[i].gols_sofridos << "gd (" << times[i].gols_feitos << "-" << times[i].gols_sofridos
			<< ")" << endl;
	}
	
}

int main(){
	int qtd_torneios;
	
	cin >> qtd_torneios;
	getchar();
	
	um_time o_time;
	o_time.gols_feitos = o_time.gols_sofridos = o_time.vitorias = o_time.empates = o_time.derrotas = 0;
	o_time.jogos_jogados = o_time.pontos = 0;
	
	f(j, 0, qtd_torneios){
		times.clear();
		id_time.clear();
	
		getline(cin, nome_torneio);
	
		cin >> qtd_times;
		getchar();
		f(i, 0, qtd_times){
			getline(cin, o_time.nome);
			times.pb(o_time);
			id_time[times[i].nome] = i;
		}
	
		cin >> qtd_partidas;
		getchar();
		char partida[1024];
		f(i, 0, qtd_partidas){
			cin.getline(partida, 1024);
			computar_partida(partida);
		}
		
		exibir_resultados();
		if(j != qtd_torneios - 1)
			cout << endl;
	}

	return 0;
}
