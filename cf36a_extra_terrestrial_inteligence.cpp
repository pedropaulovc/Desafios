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
#include<fstream>
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
string s;

int proximo1(int pos){
	int i;
	for(i = pos; i < n; i++)
		if(s[i] == '1')
			break;
	return i;
}

int main(){
	ifstream ent;
	ent.open("input.txt", ios::in);
	ofstream sai;
	sai.open("output.txt", ios::out);

	ent >> n >> s;
	
	int i = proximo1(0);
	int j = proximo1(i + 1);
	int intervalo = j - i - 1;
	
	int ant = j;
	int prox;
	while((prox = proximo1(ant + 1)) && prox - ant - 1 == intervalo && prox < n)
		ant = prox;
	
	if(prox != n)
		sai << "NO" << endl;
	else
		sai << "YES" << endl;
	return 0;
}

