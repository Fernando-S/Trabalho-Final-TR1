#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main (){
string msg;
cout << "Digite a msg" << endl;
cin >> msg;
int n = msg.size();
int mensagem[n];
int i = 0, m = 0;
int quadro_invertido[n*7], quadro[n*7];

for (i = 0; i < n; i++){
  mensagem[i] = msg[i];
}
/*  Binario
for(m = 0; m < n; m++){
  while(mensagem[m] > 0){
    quadro_invertido[i] = mensagem[m] % 2;
    mensagem[m] = mensagem[m]/2;
    i++;
  }
}

int j = n*7;

for(i = 0; i < n*7; i++){
  quadro[i] = quadro_invertido[j];
  j--;
}

*/
for (i = 0; i < n; i++){
//  quadro[i] = msg[i];
  cout << mensagem[i];
//  cout << " ";
}

  return 0;
}
