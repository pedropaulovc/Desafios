#include <iostream>
#include <iomanip>

using namespace std;

#define PERFEITO 1
#define DEFICIENTE 2
#define ABUNDANTE 3

int calcular_perfeicao(int n){
	int perfeicao = 0;
	for(int i = 1; i < n; i++){
		if(n % i == 0)
			perfeicao += i;
	}
	
	if(perfeicao < n)
		return DEFICIENTE;
	if(perfeicao > n)
		return ABUNDANTE;
	return PERFEITO;
}


int main(){
	cout << "PERFECTION OUTPUT" << endl;
	
	int num;
	while(cin >> num && num != 0){
		int perfeicao = calcular_perfeicao(num);
		
		cout << setw(5) << num << "  ";
		if(perfeicao == PERFEITO)
			cout << "PERFECT";
		else if(perfeicao == DEFICIENTE)
			cout << "DEFICIENT";
		else
			cout << "ABUNDANT";
		cout << endl;
	}
	
	cout << "END OF OUTPUT" << endl;

	return 0;
}
