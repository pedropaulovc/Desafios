#include <iostream>
#include <cmath>

using namespace std;

#define MAX_RECHEIOS 11
#define MAX_FARINHA 1001

int restante_recheio[MAX_RECHEIOS];
int lucro_recheio[MAX_RECHEIOS];
int req_recheio[MAX_RECHEIOS];
int farinha_recheio[MAX_RECHEIOS];
int lucro_maximo[MAX_RECHEIOS][MAX_FARINHA];

int buscar_lucro_maximo(int tipo_pao, int farinha_restante){
	if(lucro_maximo[tipo_pao][farinha_restante] != -1)
		return lucro_maximo[tipo_pao][farinha_restante];

	if(tipo_pao == 0){
		lucro_maximo[tipo_pao][farinha_restante] = farinha_restante / farinha_recheio[0] * lucro_recheio[0];
		return lucro_maximo[tipo_pao][farinha_restante];
	}
	
	int maior_lucro = buscar_lucro_maximo(tipo_pao - 1, farinha_restante);
	int max_paes = min(restante_recheio[tipo_pao] / req_recheio[tipo_pao], 
							farinha_restante / farinha_recheio[tipo_pao]);
	
	int novo_lucro;						
	for(int qtd_paes = 1; qtd_paes <= max_paes; qtd_paes++){
		novo_lucro = lucro_recheio[tipo_pao] * qtd_paes + 
						buscar_lucro_maximo(tipo_pao - 1, farinha_restante - farinha_recheio[tipo_pao] * qtd_paes);
		
		if(novo_lucro > maior_lucro)
			maior_lucro = novo_lucro;
	}
	
	lucro_maximo[tipo_pao][farinha_restante] = maior_lucro;
	return maior_lucro;
}

int main(){
	int qtd_farinha, qtd_recheios;
	
	//Considerando recheio 0 como o pao puro.
	restante_recheio[0] = 1000;
	req_recheio[0] = 0;
	
	cin >> qtd_farinha >> qtd_recheios >> farinha_recheio[0] >> lucro_recheio[0];
	
	for(int i = 1; i < qtd_recheios + 1; i++){
		cin >> restante_recheio[i] >> req_recheio[i] >> farinha_recheio[i] >> lucro_recheio[i];
	}
	
	for(int i = 0; i < MAX_RECHEIOS; i++)
		for(int j = 0; j < MAX_FARINHA; j++)
			lucro_maximo[i][j] = -1;

	cout << buscar_lucro_maximo(qtd_recheios, qtd_farinha);

	return 0;
}

