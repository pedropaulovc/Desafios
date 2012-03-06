#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef struct {
	int i, j;
	char id;
} coord;

typedef struct { 
	char dir;
	int qtd;
} comando;

typedef struct {
	char conteudo;
	int ns_disp, ew_disp, sn_disp, we_disp;
} pos_mapa;


pos_mapa mapa[1001][1001];
int lin, col;
vector<comando> comandos;

inline bool proximo(coord *atual, comando &comand){
	if(comand.dir == 'N' && mapa[atual->i][atual->j].sn_disp >= comand.qtd){
		atual->i -= comand.qtd;
		return true;
	}
	
	if(comand.dir == 'E' && mapa[atual->i][atual->j].we_disp >= comand.qtd){
		atual->j += comand.qtd;
		return true;
	}
	
	if(comand.dir == 'S' && mapa[atual->i][atual->j].ns_disp >= comand.qtd){
		atual->i += comand.qtd;
		return true;
	}
	
	if(comand.dir == 'W' && mapa[atual->i][atual->j].ew_disp >= comand.qtd){
		atual->j -= comand.qtd;
		return true;
	}
	
	return false;
}


bool seguir_comandos(coord inicio){
	int num_comandos = comandos.size();
	for(int i = 0; i < num_comandos; i++){
		comando atual = comandos[i];
		
		if(!proximo(&inicio, atual)){
			return false;
		}
	}
	return true;
}

void pre_processar_mapa(){
	int disp;
	for(int i = 0; i < lin; i++){
		disp = 0;
		//Varrendo W->E
		for(int j = 0; j < col; j++){
			if(mapa[i][j].conteudo == '#'){
				disp = 0;
				continue;
			}
			mapa[i][j].ew_disp = disp;
			disp++;
		}
		
		disp = 0;
		//Varrendo E->W
		for(int j = col - 1; j >= 0; j--){
			if(mapa[i][j].conteudo == '#'){
				disp = 0;
				continue;
			}
			mapa[i][j].we_disp = disp;
			disp++;
		}
	}
	
	for(int j = 0; j < col; j++){
		disp = 0;
		//Varrendo N->S
		for(int i = 0; i < lin; i++){
			if(mapa[i][j].conteudo == '#'){
				disp = 0;
				continue;
			}
			mapa[i][j].sn_disp = disp;
			disp++;
		}
		
		disp = 0;
		//Varrendo S->N
		for(int i = lin - 1; i >= 0; i--){
			if(mapa[i][j].conteudo == '#'){
				disp = 0;
				continue;
			}
			mapa[i][j].ns_disp = disp;
			disp++;
		}
	}
}

int main(){
	vector<coord> locais;
	string linha;
	coord possivel;
	
	cin >> lin >> col;
	getchar();
	
	for(int i = 0; i < lin; i++){
		for(int j = 0; j < col; j++){
			mapa[i][j].conteudo = getchar();
			
			if(mapa[i][j].conteudo >= 'A' && mapa[i][j].conteudo <= 'Z'){
				possivel.i = i;
				possivel.j = j;
				possivel.id = mapa[i][j].conteudo;
				locais.push_back(possivel);
			}
		}
		getchar();
	}
		
	int num_comandos;
	comando comand;
	cin >> num_comandos;
	
	for(int i = 0; i < num_comandos; i++){
		cin >> comand.dir >> comand.qtd;
		comandos.push_back(comand);
	}
	
	pre_processar_mapa();
	
	vector<char> respostas;
	int num_possiveis = locais.size();
	for(int i = 0; i < num_possiveis; i++){
		if(seguir_comandos(locais[i]))
			respostas.push_back(locais[i].id);
	}
	
	sort(respostas.begin(), respostas.end());
	
	int num_respostas = respostas.size();
	
	if(num_respostas == 0){
		cout << "no solution";
		return 0;
	}
	
	for(int i = 0; i < num_respostas; i++)
		cout << respostas[i];
	
	return 0;
}
