#include "CamadaFisica.h"
#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

string binarioparastring(int *vetor, int n) {
  int k, c, j = 0;
  uint i = 0;

  std::vector<char> ret;
  for (c = 0; c < n; c += 8) {
    j = 0;

    i = (vetor[c] * 128) + (vetor[c + 1] * 64) + (vetor[c + 2] * 32) +
        (vetor[c + 3] * 16) + (vetor[c + 4] * 8) + (vetor[c + 5] * 4) +
        (vetor[c + 6] * 2) + (vetor[c + 7] * 1);
    std::cout << i << std::endl;
    std::cout << static_cast<char>(i) << std::endl;
    ret.push_back(static_cast<char>(i));
    j++;
  }

  return std::string(ret.data());
}

///////////////////////////
//		Metodo Main		//
/////////////////////////
int main(void) {
  int a[8] = {0, 1, 0, 1, 1, 1, 0, 1};
  char f[8] = {0, 0, 0, 0, 0, 0, 0, 1};
  char c[3] = {97, 97, 97};
  string d = binarioparastring(a, 8);
  char *e;

  cout << "d eh: " << d << endl;
  //   cout << "b eh: " << b << endl;
  cout << "c eh: " << c << endl;
  cout << "e eh: " << e << endl;

  return 0;
}
