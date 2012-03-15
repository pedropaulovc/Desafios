#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<list>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++ )
#define FORV(it,A) for(vector<int>::iterator it = A.begin(); it!= A.end(); it++)
#define FORS(it,A) for(set<int>::iterator it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
#ifdef DEBUG
#define debug(x) x
#else
#define debug(x)
#endif
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

char mapeamento[256];
map<string, int> frequencias;

void gerar_mapeamento(){
	mapeamento['A'] = '2'; mapeamento['B'] = '2'; mapeamento['C'] = '2';
	mapeamento['D'] = '3'; mapeamento['E'] = '3'; mapeamento['F'] = '3';
	mapeamento['G'] = '4'; mapeamento['H'] = '4'; mapeamento['I'] = '4';
	mapeamento['J'] = '5'; mapeamento['K'] = '5'; mapeamento['L'] = '5';
	mapeamento['M'] = '6'; mapeamento['N'] = '6'; mapeamento['O'] = '6';
	mapeamento['P'] = '7'; mapeamento['R'] = '7';
	mapeamento['S'] = '7'; mapeamento['T'] = '8'; mapeamento['U'] = '8';
	mapeamento['V'] = '8'; mapeamento['W'] = '9'; mapeamento['X'] = '9';
	mapeamento['Y'] = '9';
}

string normalizar_numero(string tel){
	stringstream ss;
	
	int digito = 0;
	for(int i = 0; i < tel.length(); i++){
		if(tel[i] >= '0' && tel[i] <= '9'){
			ss << tel[i];
			digito++;
			if(digito == 3)
				ss << '-';
		}

		if(tel[i] >= 'A' && tel[i] <= 'Z') {
			ss << mapeamento[tel[i]];
			digito++;
			if(digito == 3)
				ss << '-';
		}
		
		
	}
	return ss.str();
}

int main(){
	int qtd_datasets, tam_dataset;
	string linha;
	map<string,int>::iterator it;
	bool possui_duplicatas;

	gerar_mapeamento();

	cin >> qtd_datasets;	
	for(int i = 0; i < qtd_datasets; i++){
		cin >> tam_dataset;
		getchar();
		frequencias.clear();
		possui_duplicatas = false;

		for(int j = 0; j < tam_dataset; j++){
			getline(cin, linha);
			frequencias[normalizar_numero(linha)]++;
		}
		
		for (it=frequencias.begin() ; it != frequencias.end(); it++ )
			if((*it).second > 1){
				cout << (*it).first << " " << (*it).second << endl;
				possui_duplicatas = true;
			}
		
		if(!possui_duplicatas)
			cout << "No duplicates." << endl;
		if(i != qtd_datasets - 1)
			cout << endl;
	}

	return 0;
}
