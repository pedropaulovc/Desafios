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

#define STAN true
#define OLLIE false
typedef bool vencedor;

vencedor descobrir_vencedor(ll n){
	if(n <= 9)
		return STAN;
	if(n <= 2 * 9)
		return OLLIE;
	if(n <= 9 * 2 * 9)
		return STAN;
	if(n <= 2 * 9 * 2 * 9)
		return OLLIE;
	if(n <= 9 * 2 * 9 * 2 * 9)
		return STAN;
	if(n <= 2 * 9 * 2 * 9 * 2 * 9)
		return OLLIE;
	if(n <= 9 * 2 * 9 * 2 * 9 * 2 * 9)
		return STAN;
	if(n <= 2 * 9 * 2 * 9 * 2 * 9 * 2 * 9)
		return OLLIE;
	if(n <= 9 * 2 * 9 * 2 * 9 * 2 * 9 * 2 * 9)
		return STAN;
	if(n <= 2 * 9 * 2 * 9 * 2 * 9 * 2 * 9 * 2 * 9)
		return OLLIE;
	if(n <= 9 * 2 * 9 * 2 * 9 * 2 * 9 * 2 * 9 * 2 * 9)
		return STAN;
	if(n <= 2 * 9 * 2 * 9 * 2 * 9 * 2 * 9 * 2 * 9 * 2 * 9)
		return OLLIE;
	if(n <= 9 * 2 * 9 * 2 * 9 * 2 * 9 * 2 * 9 * 2 * 9 * 2 * 9)
		return STAN;
	if(n <= 2 * 9 * 2 * 9 * 2 * 9 * 2 * 9 * 2 * 9 * 2 * 9 * 2 * 9)
		return OLLIE;
	
	return STAN;
}

int main(){
	ll n;
	while(cin >> n)
		if(descobrir_vencedor(n) == STAN)
			cout << "Stan wins." << endl;
		else
			cout << "Ollie wins." << endl;
	
	
	return 0;
}
