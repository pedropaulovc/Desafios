#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
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

bool parenteses_balanceados(string linha){
	stack<char> pilha;
	
	f(i,0,linha.length()){
		debug(cout << pilha.size() << " " << linha[i] << endl);
		
		if(linha[i] == '(' || linha[i] == '[')
			pilha.push(linha[i]);
		else if(pilha.size() == 0)
			return false;
		else if(linha[i] == ')' && pilha.top() == '(')
			pilha.pop();
		else if(linha[i] == ']' && pilha.top() == '[')
			pilha.pop();
		else
			return false;
	}

	if(pilha.size() == 0)	
		return true;
	return false;
}

int main(){
	int num_entradas;
	string linha;
	cin >> num_entradas;
	
	getchar();
	f(i, 0, num_entradas){
		getline(cin, linha);
		if(parenteses_balanceados(linha))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	
	return 0;
}
