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

int c[101][101];
int m, n;
vector<int> x, y;

int calcular_comprimento_lcs(){
	f(i, 0, m + 1)
		c[i][0] = 0;
	f(j, 0, n + 1)
		c[0][j] = 0;
		
	f(i, 1, m + 1)
		f(j, 1, n + 1)
			if(x[i - 1] == y[j - 1])
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
	return c[m][n];
}

int main(){
	int num, atual = 1;
	bool primeiro = true;

	while(cin >> m >> n && m != 0 || n != 0){
		x.clear();
		y.clear();
		
		f(i, 0, m){
			cin >> num;
			x.pb(num);
		}

		f(i, 0, n){
			cin >> num;
			y.pb(num);
		}
		
		cout << "Twin Towers #" << atual << endl;
		cout << "Number of Tiles : " << calcular_comprimento_lcs() << endl << endl;
		atual++;
	}
	
	return 0;
}
