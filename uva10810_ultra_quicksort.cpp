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

ll entrada[500000];
ll tmp[500000];
ll inversoes;
int tam_vetor;

void intercala(ll *vetor, int p, int r){
	int meio = (p + r) / 2;
	int i_tmp = 0;
    int i_esq = p;
    int i_dir = meio + 1;
    
	while(i_esq <= meio && i_dir <= r)
		if(vetor[i_esq] < vetor[i_dir])
			tmp[i_tmp++] = vetor[i_esq++];
		else {
			tmp[i_tmp++] = vetor[i_dir++];
			debug(cout << "->" << meio - i_esq + 1 << endl;)
			inversoes += meio - i_esq + 1;
		}
	
	while(i_esq <= meio)
		tmp[i_tmp++] = vetor[i_esq++];
	
	while(i_dir <= r)
		tmp[i_tmp++] = vetor[i_dir++];
	
    for (int i = p; i <= r; i++)
        vetor[i] = tmp[i - p];
}

void merge_sort(ll *vetor, int p, int r){
	if(r - p <= 0)
		return;
	int meio = (p + r)/2;
	merge_sort(vetor, p, meio);
	merge_sort(vetor, meio + 1, r);
	intercala(vetor, p, r);
}

void imprime_vetor(){
	f(i, 0, tam_vetor)
		cout << entrada[i] << " ";
	cout << endl;
}

int main(){

	while(cin >> tam_vetor && tam_vetor){
		inversoes = 0;
		f(i, 0, tam_vetor)
			cin >> entrada[i];
		merge_sort(entrada, 0, tam_vetor - 1);
		debug(imprime_vetor();)
		cout << inversoes << endl;
	}

	return 0;
}
