#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstdio>

using namespace std;

typedef struct {
	int qtd, custo;
} opcao;

#define MAX_QTD 101
#define MAX_OPCOES 6

class VolumeDiscount {
vector<opcao> opcoes;
int menores_custos[MAX_QTD][MAX_OPCOES];

public:
	int bestDeal(vector <string> priceList, int quantity);
	int obter_menor_custo(int opcao, int qtd);
};

int VolumeDiscount::obter_menor_custo(int opcao, int qtd) {
	if(menores_custos[qtd][opcao] != -1)
		return menores_custos[qtd][opcao];

	int max_compras = ceil(1.0 * qtd / opcoes[opcao].qtd);
	
	if(opcao == 0)
		return opcoes[0].custo * max_compras;
	
	int menor_custo = obter_menor_custo(opcao - 1, qtd);
	int custo_tmp;
	for(int i = 1; i <= max_compras; i++){
		custo_tmp = i * opcoes[opcao].custo;
		custo_tmp += obter_menor_custo(opcao - 1, qtd - i * opcoes[opcao].qtd);
		
		if(custo_tmp < menor_custo){
			menor_custo = custo_tmp;
		}

	}
	
	menores_custos[qtd][opcao] = menor_custo;
	return menor_custo;
}

int VolumeDiscount::bestDeal(vector <string> priceList, int quantity){
	for(int i = 0; i < MAX_QTD; i++){
		for(int j = 0; j < MAX_OPCOES; j++){
			menores_custos[i][j] = -1;
		}
	}

	stringstream ss;
	int tam = priceList.size();
	opcao op;
	for(int i = 0; i < 	tam; i++){
		ss << priceList[i] << " ";
		ss >> op.qtd >> op.custo;
		opcoes.push_back(op);
	}

	return obter_menor_custo(tam - 1, quantity);
}

int main(){
	int qtd;
	string linha;
	vector<string> priceList;
	VolumeDiscount vd;
	
	cin >> qtd;
	getchar();
	while(getline(cin, linha)){
		priceList.push_back(linha);
	}
	
	cout << vd.bestDeal(priceList, qtd);
	
	return 0;
}
