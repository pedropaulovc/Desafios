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

string ent;
vector<string> dados;

bool compara(string a, string b){
	return a.size() > b.size();
}

bool testa_decodabilidade(){
	dados.clear();
	while(ent != "9"){
		dados.pb(ent);
		cin >> ent;
	}
	
	sort(dados.begin(), dados.end(), compara);
	
	f(i, 0, dados.size() - 1){
		f(j, i + 1, dados.size()){
//			cout << dados[i] << " find " << dados[j] << endl;
			if(dados[i].find(dados[j]) == 0)
				return false;
		}
	}
	
	return true;
}

int main(){
	int i = 1;
	while(cin >> ent){
		if(testa_decodabilidade())
			cout << "Set " << i << " is immediately decodable" << endl;
		else
			cout << "Set " << i << " is not immediately decodable" << endl;
		i++;
	}
		
	return 0;
}
