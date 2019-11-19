#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>



using namespace std;

int main (){
  int size = 10;
  int quadro[10] = {1, 1, 1, 0, 1, 0, 1, 1, 0, 1};
  int manchesterD[2*size];
	int i;
  int bitAnterior = 1; //bit antes do começo da análise do quadro para codificação
  cout << "Quadro: ";
  for(i = 0; i<10; i++){
    cout << quadro[i];
    }
	for(i = 0; i<size; i++){
	   manchesterD[2*i] = 0;
	   manchesterD[2*i + 1] = 1;
  }
/*  for(i=0; i<size; i++){
    manchesterD[2*i] ^= 1;
    cout << manchesterD[i];
  }// TOGGLE*/
  cout << "\nClock: ";
  for(i = 0; i<2*size; i++){
    cout << manchesterD[i];
  }
  cout << "\nManchester D: ";
  for (i=0; i<size; i++){
    if(i == 0){
      if(quadro[0] == 1){
        manchesterD[2*i] = bitAnterior;
        manchesterD[2*i + 1] ^= manchesterD[2*i];
      }
      else if (quadro[0] == 0){
        manchesterD[2*1] ^= bitAnterior;
        manchesterD[2*i + 1] ^= manchesterD[2*i];
      }
    }
    else{
      if(quadro[i] == 1){
        manchesterD[2*i] = manchesterD[2*i - 1];
        manchesterD[2*i + 1] ^= manchesterD[2*i];
      }
      else if(quadro[i] == 0){
        if(i > 0){
          manchesterD[2*i] = manchesterD[2*i - 2];
          manchesterD[2*i + 1] = manchesterD[2*i - 1];
        }
      }
    }
  }

  for(i=0; i<2*size; i++){
    cout << manchesterD[i];
  }

  //DECODIFICAÇAO
  int clk[2*size];

  for(i = 0; i<size; i++){
	   clk[2*i] = 0;
	   clk[2*i + 1] = 1;
  }
  cout << "\nClock: ";
  for(i = 0; i<2*size; i++){
    cout << clk[i];
  }

  int quadroDecod[size];

// [2*n -1] == [2*n]
  cout << "\nDecodificado: ";
  for(i=0; i<size; i++){
    if(i == 0){
      if(manchesterD[0] == bitAnterior){
        quadroDecod[0] = 1;
      }
      else if (manchesterD[0] != bitAnterior){
        quadroDecod[0] = 1;
      }
    }
    else{
      if(manchesterD[2*i] == manchesterD[2*i - 1])
        quadroDecod[i] = 1;
      else
        quadroDecod[i] = 0;
    }
    cout << quadroDecod[i];
  }

  return 0;
}
