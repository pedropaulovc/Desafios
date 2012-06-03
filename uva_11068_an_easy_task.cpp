#include<iostream>
#include<iomanip>
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

double a, c, b, d, e, f, x, y;

bool calcular_ponto_fixo(){
	double D  = a * d - c * b;
	double Dx = e * d - f * b;
	double Dy = a * f - c * e;
	
	if(D == 0)
		return false;
	x = Dx == 0 ? 0 : Dx/D;
	y = Dy == 0 ? 0 : Dy/D;
	return true;
}

bool ler_entrada(){
	return cin >> a >> b >> e >> c >> d >> f && 
		(a != 0 || a != 0 || c != 0 || b != 0 || d != 0 || e != 0 || f != 0);
}

int main(){
	
	while (ler_entrada()){
		if(calcular_ponto_fixo())
			cout << "The fixed point is at " << setiosflags(ios::fixed) << setprecision(2) << 
			x << " " << setprecision(2) << y << endl;
		else
			cout << "No fixed point exists." << endl;
	} 
	return 0;
}

