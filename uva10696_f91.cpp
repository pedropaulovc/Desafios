#include <iostream>

using namespace std;

int main(){
  int num;

  while(cin >> num && num){
    cout << "f91(" << num << ") = ";

    if(num <= 100)
      cout << 91;
    else
      cout << num - 10;
    cout << endl;
  }

  return 0;
}

