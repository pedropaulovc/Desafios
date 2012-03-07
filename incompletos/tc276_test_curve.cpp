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
#define round(x) x <= 0.5 ? floor(x) : ceil(x)
#ifdef DEBUG
#define debug(x) x
#else
#define debug(x)
#endif
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

vector<int>  determineGrades(vector<int> scores){
	int max = scores[0];

	int len = scores.size();
	for(int i = 0; i < len; i++){
		if(scores[i] > max)
			max = scores[i];
	}
	
	double coef = 100.0/max;
	debug(cout << coef << endl;)
		
	for(int i = 0; i < len; i++){
		scores[i] = scores[i] * coef;
	}
	
	return scores;
}

int main(){
	int qtd_scores, atual;
	cin >> qtd_scores;
	
	vector<int> scores;
	f(i, 0, qtd_scores){
		cin >> atual;
		scores.pb(atual);
	}
	
	scores = determineGrades(scores);
	
	cout << qtd_scores << endl;
	f(i, 0, qtd_scores){
		cout << scores[i] << endl;
	}
	
	
	return 0;
}
