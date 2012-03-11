#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<cstdio>
using namespace std;
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++ )

#define MAX_FUNCOES 51

vector<string> funcoes;
int grafo[MAX_FUNCOES][MAX_FUNCOES];
int qtd_funcoes;

class FunctionDependency {
public:
	vector<string> scriptingOrder(vector<string> funcs, vector<string> depends);
};

class comparador {
public:
  bool operator() (const int& lhs, const int&rhs) const {
    return funcoes[lhs] > funcoes[rhs];
  }
};

typedef priority_queue<int,vector<int>, comparador> fila_prioridade;

int calcular_grau_entrada(int no){
	int grau_entrada = 0;	
	
	f(i, 0, qtd_funcoes){
		if(grafo[i][no])
			grau_entrada++;
	}
	
	return grau_entrada;
}

vector<int> gerar_ordenamento_topologico(){
	vector<int> ord_top;
	fila_prioridade fp;
	int atual;
	
	f(i, 0, qtd_funcoes){
		if(calcular_grau_entrada(i) == 0){
			fp.push(i);
		}
	}
	
	while(fp.size()){
		atual = fp.top();
		ord_top.pb(atual);
		fp.pop();
		
		f(j, 0, qtd_funcoes){
			if(!grafo[atual][j])
				continue;

			grafo[atual][j] = 0;
			if(calcular_grau_entrada(j) == 0){
				fp.push(j);
			}
		}
	}
	
	return ord_top;
}

vector<string> FunctionDependency::scriptingOrder(vector<string> funcs, vector<string> depends){
	int dependencia;
	qtd_funcoes = funcs.size();
	funcoes = funcs;
	
	f(i, 0, MAX_FUNCOES)
		f(j, 0, MAX_FUNCOES)
			grafo[i][j] = 0;

	string linha;
	stringstream ss;
	f(dependente, 0, qtd_funcoes){
		linha = depends[dependente];
		ss.clear();
		ss << linha << " ";
		while(ss >> dependencia) {
			grafo[dependencia][dependente] = 1;
		}
	}
	
	vector<int> ord_top = gerar_ordenamento_topologico();
	vector<string> ord_top_string;
	
	f(i, 0, qtd_funcoes){
		ord_top_string.pb(funcs[ord_top[i]]);
	}
	
	return ord_top_string;
}

int main(){
	int dependencia;
	cin >> qtd_funcoes;
	getchar();

	string linha;
	vector<string> funcs;
	f(i, 0, qtd_funcoes){
		getline(cin, linha);
		funcs.pb(linha);
	}
	
	cin >> qtd_funcoes;
	getchar();
	
	stringstream ss;
	vector<string> depends;
	f(i, 0, qtd_funcoes){
		getline(cin, linha);
		depends.pb(linha);
	}
	
	FunctionDependency fd;
	vector<string> ord_top = fd.scriptingOrder(funcs, depends);
	
	cout << qtd_funcoes << endl;
	f(i, 0, qtd_funcoes){
		cout << ord_top[i] << endl;
	}
	
	
	return 0;
}
