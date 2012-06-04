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

ll triang[100100];
ll produto[100200];

int main(){
	ll maxtriang = ceil(sqrt(10000000000));
	f(i, 1, maxtriang)
		triang[i] = (i % 2 == 0 ? i/2 : i);
	f(i, 1, maxtriang)
		produto[i] = triang[i] * triang[i + 1];


	int n;
	scanf("%d", &n);
	
	
	ll i = 1;
	while(produto[i] < n)
		i++;

	ll j;
	while(i > 0 && produto[i] >= n/2){
		j = 1;
		while(j <= i){
			if(produto[i] + produto[j] == n){
				printf("YES\n");
				return 0;
			}
			j++;
		}
		i--;
	}
	
	printf("NO\n");
	return 0;
}
