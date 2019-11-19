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
    int size = 0;

    for (i = 0; i < n; i++){
      mensagem[i] = msg[i];
    }

    i=0;

    int o = 0, soma = 0;

    for(m = 0; m < n; m++){
      i = 0;
      while(mensagem[m] > 0){
        quadro_invertido[i] = mensagem[m]%2;
        mensagem[m] /= 2;
        i++;
      }
      size += i;
      int j = i-1;
      soma = o + i;
      while(o < (soma)){
        quadro[o] = quadro_invertido[j];
        o++;
        j--;
      }
    }


for (m = 0; m < size; m++){
  cout << quadro[m];
}

cout << endl;

//cout << quadro << endl;
  return 0;
}
