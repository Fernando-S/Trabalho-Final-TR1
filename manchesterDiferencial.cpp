#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

int main (){
  int size = 10;
  int quadro[10] = {0, 1, 0, 0, 1, 0, 1, 1, 0, 1};
  int manchesterD[2*size];
	int i;
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

  for(i=0; i<2*size; i++){
    cout << manchesterD[i];
  }

  return 0;
}
