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

ll capacidade_robo;
stack<ll> pilha;
deque<ll> robo;
bool topo_robo = true;

void empilha(ll num){
	if(topo_robo)
		robo.push_front(num);
	else
		robo.push_back(num);
	
	if(robo.size() > capacidade_robo){
		if(topo_robo){
			pilha.push(robo.back());
			robo.pop_back();
		} else {
			pilha.push(robo.front());
			robo.pop_front();		
		}
	}
}

ll desempilha(){
	ll sai;	
	
	if(topo_robo) {
		sai = robo.front();
		robo.pop_front();
	} else {
		sai = robo.back();
		robo.pop_back();
	}
	
	if(pilha.size() > 0) {
		if(topo_robo)
			robo.push_back(pilha.top());
		else
			robo.push_front(pilha.top());
		
		pilha.pop();
	}
	
	return sai;
}

int main(){
	cin >> capacidade_robo;

	int atual;
	while(cin >> atual && atual){
		switch(atual){
		case -1:
			cout << desempilha() << endl;
			break;
		case -2:
			topo_robo = !topo_robo;
			break;
		default:
			empilha(atual);
			break;
		}
	}
	
	return 0;
}


