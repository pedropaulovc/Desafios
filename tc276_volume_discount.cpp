#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

typedef struct {
	int qtd, custo;
} opcao;

class VolumeDiscount {
vector<opcao> opcoes;
int menores_custos[101][6];

public:
	int bestDeal(vector <string> priceList, int quantity);
	int obter_menor_custo(int opcao, int qtd);
};

int VolumeDiscount::obter_menor_custo(int opcao, int qtd) {
	if(menores_custos[qtd][opcao] != -1)
		return menores_custos[qtd][opcao];

	int max_compras = ceil(1.0 * qtd / opcoes[0].qtd);

	cout << opcao << " " << qtd << " " << max_compras << endl;
	
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
	for(int i = 0; i < 101; i++){
		for(int j = 0; j < 6; j++){
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
	VolumeDiscount vd;
	vector<string> priceList;
	priceList.push_back("2 272");
	priceList.push_back("1 166");
	priceList.push_back("10 993");

	cout << vd.bestDeal(priceList, 81);
	return 0;
}
