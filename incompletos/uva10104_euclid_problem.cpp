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

typedef struct {
	int x, y, d;
} coef;

int gcd(ll a, ll b){
	while(true){
		if(a == 0)
			return b;
		if(b == 0)
			return a;
		
		if(b < a){
			ll tmp = b;
			b = a;
			a = tmp;
		}
		
		b = b % a;
	}
	
	return 0;
}

coef calcular_algoritmo_euclides(ll a, ll b){
	if(a < b)
		return calcular_algoritmo_euclides(b, a);

	ll mod, quoc;	
	ll x1 = 1;
	ll y1 = 0;

	ll x2 = 0;
	ll y2 = 1;

	ll tmpx = a, tmpy = b;
	while(mod != 0){
		debug(cout << tmpx << " " << x1 << " " << y1 << endl;)
		debug(cout << tmpy << " " << x2 << " " << y2 << endl << endl;)
		
		mod = a % b;
		quoc = a / b;

		tmpx = x1 - x2 * quoc;
		tmpy = y1 - y2 * quoc;

		x1 = x2;
		y1 = y2;
		
		x2 = tmpx;
		y2 = tmpy;
		
		a = b;
		b = mod;
	}
	
	coef coefs;
	
	coefs.x = x1;
	coefs.y = y1;
	coefs.d = a;
	
	return coefs;
}

int main(){
	ll a, b;
	
	coef coefs;
	while(cin >> a >> b){
		coefs = calcular_algoritmo_euclides(a, b);
		cout << coefs.x << " " << coefs.y << " " << coefs.d << endl;
	}
	
	return 0;
}
