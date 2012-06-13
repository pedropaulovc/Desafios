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

class comparador
{
public:
  bool operator() (const int& lhs, const int&rhs) const
  {
    return lhs > rhs;
  }
};

int N;
priority_queue< int, vector<int>, comparador > fila;


int main(){
	int num;
	while(cin >> N && N > 0){
		while(!fila.empty())
			fila.pop();
		f(i, 0, N){
			cin >> num;
			fila.push(num);
		}

		ll custo = 0;
		int n1, n2;
		while(fila.size() != 1){
			n1 = fila.top();
			fila.pop();
			n2 = fila.top();
			fila.pop();
			
			custo += n1 + n2;
			fila.push(n1 + n2);
		}
				
		cout << custo << endl;
	}
	return 0;
}
