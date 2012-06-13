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

#define PI 3.141592653589793
#define dist(p, q) sqrt(quad(p.x - q.x) + quad(p.y - q.y))

typedef struct {
	double x, y;
} ponto;

ponto p1, p2, p3;

double arredonda(double x){
	return floor(x * 100 + 0.5)/100;
}

double calcula_circunferencia(){
	double a = dist(p1, p2);
	double b = dist(p1, p3);
	double c = dist(p2, p3);
	
	return arredonda(2 * a * b * c / sqrt((a + b + c) * (-a + b + c) * (a - b + c) * (a + b -c)) * PI);
}

int main(){
	while(cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y)
		printf("%.2f\n", calcula_circunferencia());
	
	return 0;
}
