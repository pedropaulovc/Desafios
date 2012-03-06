/*
 * 10258-contestScoreboard.cpp
 *
 *  Created on: Feb 17, 2012
 *      Author: pedropaulovc
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef struct {
	int problema[11]; //Tempo negativo indica que o problema ainda não foi completado
	int penalidade;
	int resolvidos;
	int id;
} participante;

bool melhor_participante(participante p1, participante p2) {
	if (p1.resolvidos != p2.resolvidos)
		return p1.resolvidos > p2.resolvidos;
	if (p1.penalidade != p2.penalidade)
		return p1.penalidade < p2.penalidade;
	return p1.id < p2.id;
}

int main_10258() {
	int num_entradas, num_part, num_prob, tempo;
	char status;
	vector<participante> parts;
	string linha;

	cin >> num_entradas;
	getline(cin, linha);
	getline(cin, linha);
	for (int i = 0; i < num_entradas; i++) {
		parts.clear();
		parts.insert(parts.end(), 101, participante());

		while (getline(cin, linha) && linha.length() != 0) {
			sscanf(linha.c_str(), "%d %d %d %c", &num_part, &num_prob, &tempo,
					&status);
			parts[num_part].id = num_part;

			if (parts[num_part].problema[num_prob] > 0)
				continue;

			if (status == 'I')
				parts[num_part].problema[num_prob] -= 20;
			else if (status == 'C') {
				parts[num_part].problema[num_prob] *= -1;
				parts[num_part].problema[num_prob] += tempo;
				parts[num_part].resolvidos++;
				parts[num_part].penalidade +=
						parts[num_part].problema[num_prob];
			}

		}

		sort(parts.begin(), parts.end(), melhor_participante);

		for (int j = 0; j < 101; j++) {
			if (parts[j].id != 0)
				cout << parts[j].id << " " << parts[j].resolvidos << " "
						<< parts[j].penalidade << endl;
		}

		if(i != num_entradas - 1)
			cout << endl;
	}

	return 0;
}

