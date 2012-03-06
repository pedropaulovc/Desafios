#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int speed, ram, hdd, cost, id;
	bool eliminado;
} laptop;

bool menor_custo(laptop l1, laptop l2){
	return l1.cost < l2.cost;
}

int main(){
	int num_entradas;	
	cin >> num_entradas;
	
	laptop lap;
	vector<laptop> laptops;
	for(int i = 1 ; i <= num_entradas; i++){
		cin >> lap.speed >> lap.ram >> lap.hdd >> lap.cost;
		lap.id = i;
		lap.eliminado = false;
		laptops.push_back(lap);
	}
	
	for(int i = 0; i < num_entradas; i++){
		for(int j = 0; j < num_entradas; j++){
			if(laptops[i].speed > laptops[j].speed &&
				laptops[i].ram > laptops[j].ram &&
				laptops[i].hdd > laptops[j].hdd){

				laptops[j].eliminado = true;
			}
		}
	}

	sort(laptops.begin(), laptops.end(), menor_custo);
	
//	for(int i = 0; i < num_entradas; i++){
//		cout << laptops[i].id << " " << laptops[i].eliminado << endl;
//	}
	
	int i = 0;
	while(laptops[i].eliminado){
		i++;
	}	
		
	cout << laptops[i].id;
	
	return 0;
}
