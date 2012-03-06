/*
 * 10142-australianVoting.cpp
 *
 *  Created on: Feb 20, 2012
 *      Author: pedropaulovc
 */

#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int v[20];
} voto;

typedef struct {
	string nome;
	bool eliminado;
} candidato;

void ler_votos(vector<candidato> *candidatos, vector<voto> *votos) {
	int num_candidatos;
	stringstream ss(ios_base::in | ios_base::out);

	cin >> num_candidatos;
	candidato cand;
	cand.eliminado = false;
	for (int i = 0; i < num_candidatos + 1; i++) {
		getline(cin, cand.nome);
		candidatos->push_back(cand);
	}

	string linha;
	voto voto;
	while (getline(cin, linha).good() && linha != "") {
		ss << linha << " ";
		for (int j = 0; j < num_candidatos; j++)
			ss >> voto.v[j];
		votos->push_back(voto);
	}
}

vector<int> processar_rodada(vector<candidato> *candidatos,
		vector<voto> *votos) {
	int num_votos = votos->size();
	int num_candidatos = candidatos->size() - 1;
	vector<int> resultado(21);

	int pref;
	for (int i = 0; i < num_votos; i++) {
		pref = 0;
		while (pref <= num_candidatos
				&& candidatos->at(votos->at(i).v[pref]).eliminado)
			pref++;

		if (pref <= num_candidatos)
			resultado[votos->at(i).v[pref]]++;
	}

	int vencedor = 1;
	while(candidatos->at(vencedor).eliminado)
		vencedor++;

	int pontos_vencedor = resultado[vencedor];
	int pontos_perdedor = pontos_vencedor;
	bool empate = true;
	for (int i = 2; i < num_candidatos + 1; i++) {
		if (!candidatos->at(i).eliminado && resultado[i] != resultado[vencedor])
			empate = false;
		if (resultado[i] > resultado[vencedor]) {
			vencedor = i;
			pontos_vencedor = resultado[vencedor];
		}
		if(resultado[i] > 0 && resultado[i] < pontos_perdedor)
			pontos_perdedor = resultado[i];
	}

	vector<int> perdedores;
	for(int i = 1; i < num_candidatos + 1; i++)
		if(resultado[i] == pontos_perdedor)
			perdedores.push_back(i);

	vector<int> vencedores;
	if (pontos_vencedor > num_votos / 2){
		vencedores.push_back(vencedor);
	}
	else if (empate) {
		for (int i = 1; i < num_candidatos + 1; i++)
			if (resultado[i] != 0)
				vencedores.push_back(i);
	} else{
		int num_perdedores = perdedores.size();
		for(int i = 0; i < num_perdedores; i++)
			candidatos->at(perdedores[i]).eliminado = true;
	}

	return vencedores;
}

int main_10142() {
	int num_entradas;
	vector<candidato> candidatos;
	vector<voto> votos;
	vector<int> vencedores;

	cin >> num_entradas;
	for (int i = 0; i < num_entradas; i++) {
		candidatos.clear();
		votos.clear();
		vencedores.clear();

		ler_votos(&candidatos, &votos);
		do {
			vencedores = processar_rodada(&candidatos, &votos);
		} while (vencedores.size() == 0);

		sort(vencedores.begin(), vencedores.end());

		int num_vencedores = vencedores.size();
		for (int j = 0; j < num_vencedores; j++)
			cout << candidatos[vencedores[j]].nome << endl;

		if (i != num_entradas - 1)
			cout << endl;
	}

	return 0;
}
