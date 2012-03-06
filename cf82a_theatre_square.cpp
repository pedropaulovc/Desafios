#include <iostream>
#include <string>

using namespace std;

typedef struct {
	char suit, rank;
} carta;

char ranks[] = {'6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
//string ranks = "6789TJQKA";

bool maior_rank(char r1, char r2){
	int pos_1 = 0, pos_2 = 0;

	while(r1 != ranks[pos_1])
		pos_1++;
	while(r2 != ranks[pos_2])
		pos_2++;

	return pos_1 > pos_2;
}

bool maior_carta(carta c1, carta c2, char trumph){
	if(c1.suit == trumph && c2.suit != trumph)
		return true;
	if(c1.suit != c2.suit)
		return false;
	return maior_rank(c1.rank, c2.rank);
}

int main(){
	char trumph;
	string cartas;

	cin >> trumph;
	getline(cin, cartas);
	getline(cin, cartas);

	carta c1, c2;

	c1.rank = cartas[0];
	c1.suit = cartas[1];
	c2.rank = cartas[3];
	c2.suit = cartas[4];

	if(maior_carta(c1, c2, trumph))
		cout << "YES";
	else
		cout << "NO";
}
