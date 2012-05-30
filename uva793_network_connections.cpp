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

int n;
vector<int> pai, rank;

void init_unionfind(int n){
	pai.clear();
	rank.clear();
	
	f(i, 0,	n + 1){
		pai.pb(i);
		rank.pb(1);
	}
}

int find(int n){
	if(pai[n] != n)
		pai[n] = find(pai[n]);
	return pai[n];
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	
	if(rank[a] < rank[b])
		swap(a, b);	
	
	pai[b] = a;
	rank[a] += rank[b];
}

int main(){
	int qtd_testes;
	cin >> qtd_testes;
	
	char c;
	int a, b;
	stringstream ss;
	string linha;
	
	bool primeiro = true;
	f(i, 0, qtd_testes){
		if(!primeiro)
			cout << endl;
		primeiro = false;
	
		cin >> n;
		init_unionfind(n);
		int sucesso = 0, fracasso = 0;
		
		getchar();
		getline(cin, linha);
		while(linha != ""){
			ss.clear();	
			ss << linha;
			ss >> c >> a >> b;
			debug(cout << c << a << "(" << find(a) << ")" << b <<  "(" << find(b) << ")" << endl);
			
			if(c == 'c')
				unite(a, b);
			if(c == 'q')
				find(a) == find(b) ? sucesso++ : fracasso++;
			
			
			getline(cin, linha);
		}
		
		cout << sucesso << "," << fracasso << endl;
	}
	
	
	return 0;
}
