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

int n, p;
vector<int> seq;
vector<int> atuais;
int pd

int solve(int pos){
	
}

int main(){
	int j;
	while(cin >> n >> p && !(n == 0 && p == 0)){
		seq.clear();
		
		f(i, 0, n){
			cin >> j;
			seq.pb(j);
		}
		
		f(i, 0, p)
			atuais.pb(seq[i]);
			
		solve(p);
	}
	
	
	return 0;
}
