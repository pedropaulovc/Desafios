/*
 * 343-cryptKicker.cpp
 *
 *  Created on: Feb 11, 2012
 *      Author: pedropaulovc
 */

#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef struct {
	list<string> tam[17];
} dicionario;

//A tabela de tradução é uma bijeção.
typedef struct {
	char ida[255]; //l['x'] = 'g'  indica o mapeamento 'x' -> 'g'
	char volta[255]; //usados['m'] = 'b' indica que 'm' já é imagem de 'b'.
} tabela;

dicionario dict;
tabela tab;
vector<string> cifradas;
char traducao[17];

void zerar_tabela(tabela &aTabela) {
	for (int i = 0; i < 255; i++) {
		aTabela.ida[i] = 0;
		aTabela.volta[i] = 0;
	}
}

void montar_dicionario() {
	int tamDict;
	cin >> tamDict;

	string entrada;
	for (int i = 0; i < tamDict; i++) {
		cin >> entrada;
		dict.tam[entrada.length()].push_back(entrada);
	}
}

bool atualiza_tabela(string chave, string valor) {
	int len = chave.length();
	tabela backup = tab;

	//ifs dentro do for evita que uma palavra sobrescreva um mapeamento já realizado,
	//seja pela própria palavra (Ex. abaixo) ou por uma palavra anterior.
	//Ex. chave = ajmwuvjr, valor = alphabet geram uma tradução
	//ajmwuvjr -> aephabet
	for (int i = 0; i < len; i++) {
		if (tab.ida[chave.at(i)] != valor.at(i) && tab.ida[chave.at(i)] != 0) {
			tab = backup;
			return false;
		}

		if (tab.volta[valor.at(i)] != chave.at(i)
				&& tab.volta[valor.at(i)] != 0) {
			tab = backup;
			return false;
		}

		tab.ida[chave[i]] = valor[i];
		tab.volta[valor[i]] = chave[i];
	}

	return true;
}

void desfaz_tabela(string chave, string valor) {
	int len = chave.length();

	for (int i = 0; i < len; i++) {
		tab.ida[chave[i]] = 0;
		tab.volta[valor[i]] = 0;
	}
}

bool tentar_traduzir(string cifrada) {
	int len = cifrada.length();
	int i;
	for (i = 0; i < len; i++)
		traducao[i] = tab.ida[cifrada.at(i)];
	traducao[i] = '\0';

	return (find(dict.tam[len].begin(), dict.tam[len].end(), string(traducao))
			!= dict.tam[len].end());
}

bool calcular_mapeamento(unsigned int pos_atual, dicionario disp) {
	if (pos_atual == cifradas.size())
		return true;

	string cifrada = cifradas[pos_atual];
	list<string> &candidatas = disp.tam[cifrada.length()];

	if (tentar_traduzir(cifrada))
		return calcular_mapeamento(pos_atual + 1, disp);

	unsigned int num_tentativas = 1;
	while (num_tentativas <= candidatas.size()) {
		string candidata = candidatas.front();
		candidatas.pop_front();
		if (!atualiza_tabela(cifrada, candidata)) {
			candidatas.push_back(candidata);
			num_tentativas++;
			continue;
		}

		if (calcular_mapeamento(pos_atual + 1, disp))
			return true;

		desfaz_tabela(cifrada, candidata);
		candidatas.push_back(candidata);
		num_tentativas++;
	}

	return false;
}

void imprimir_resposta(string linha, bool possivel) {
	int len = linha.length();

	for (int i = 0; i < len; i++) {
		char atual = linha[i];
		if (atual == ' ')
			cout << ' ';
		else if (possivel)
			cout << tab.ida[atual];
		else
			cout << '*';
	}

	cout << endl;
}

bool maior_tamanho(string a, string b) {
	return (a.length() > b.length());
}

int main_843(int argc, char** argv) {
	montar_dicionario();

	string linha;
	getline(cin, linha);
	while (getline(cin, linha).good()) {
		zerar_tabela(tab);
		cifradas.clear();

		istringstream iss(linha);
		while (iss) {
			string subs;
			iss >> subs;
			if (subs != "")
				cifradas.push_back(subs);
		}

		//Otimização, começar pelas palavras maiores
		sort(cifradas.begin(), cifradas.end(), maior_tamanho);

		if (calcular_mapeamento(0, dict))
			imprimir_resposta(linha, true);
		else
			imprimir_resposta(linha, false);
	}

	return 0;
}
