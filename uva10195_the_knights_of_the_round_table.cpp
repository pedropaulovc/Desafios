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

double arredonda(double a){
	return floor(a * 1000 + 0.5)/1000;
}

int main(){
	double a, b, c, k, p, s, maximo;
	cout.precision(3);
	cout.setf(ios::fixed,ios::floatfield);
	while(cin >> a >> b >> c){
		if(a + b == 0 || a + c == 0 || b + c == 0){
			maximo = max(a, b);
			maximo = max(maximo, c);
			cout << "The radius of the round table is: " << arredonda(maximo) << endl;
			continue;
		}
		
		p = a + b + c;
		s = p/2;
		cout << "The radius of the round table is: " << arredonda(sqrt((s - a)*(s-b)*(s-c)/s)) << endl;
		
	}
	
	
	return 0;
}
