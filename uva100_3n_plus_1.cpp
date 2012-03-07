#include <iostream>


using namespace std;

int calcular_ciclo(long long n){
	int tam = 1;
	
	while(n != 1){
		if(n % 2 == 1)
			n = 3 * n + 1;
		else
			n /= 2;
		
		tam++;
	}

	return tam;
}


int main(){
	int i, j, min, max, maior_ciclo, ciclo;
	
	while(cin >> i >> j){
		if(i < j){
			min = i;
			max = j;
		} else {
			min = j;
			max = i;
		}
		
		maior_ciclo = calcular_ciclo(min);
		
		for(int k = min + 1; k <= max; k++){
			ciclo = calcular_ciclo(k);
			if(ciclo > maior_ciclo)
				maior_ciclo = ciclo;
		}
				
		cout << i << " " << j << " " << maior_ciclo << endl;
	}
	
	return 0;
}
