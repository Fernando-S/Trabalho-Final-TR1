#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <string>
//#include "CamadaFisica.h"

using namespace std;

string binarioparastring(int *vetor, int n) {
  int k, c, j = 0;
  uint i = 0;

  std::vector<char> ret;
  for (c = 0; c < n; c += 7) {
    i = /*(vetor[c] * 128)*/ + (vetor[c /*+ 1*/] * 64) + (vetor[c + 1] * 32) +
        (vetor[c + 2] * 16) + (vetor[c + 3] * 8) + (vetor[c + 4] * 4) +
        (vetor[c + 5] * 2) + (vetor[c + 6] * 1);
    ret.push_back(static_cast<char>(i));
  }
  ret.push_back('\0');

  return std::string(ret.data());
}

///////////////////////////
//		Metodo Main		//
/////////////////////////
int main(void) {
  /*int a[48] = {0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1,
               0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1,
               0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1};
  /*vector<int> avec;
  for (auto i = 0; i < 8; i++) {
    avec.push_back(a[i]);
  }
  char f[8] = {0, 0, 0, 0, 0, 0, 0, 1};
  char c[3] = {97, 97, 97};
  string d = *codigodehamming(a, 48);

  cout << "d eh: " << d << endl;
  //   cout << "b eh: " << b << endl;
  cout << "c eh: " << c << endl;
*/
  int a[21] = {1,1,0,0,0,0,1,0,1,0,0,0,0,0,1,1,0,0,0,1,0};
  cout << binarioparastring(a, 21) << endl;
  return 0;
}
/*
// codigodehamming1 codifica o dado no codigo de hamming byte a byte
std::vector<int> codigodehamming1(vector<int> avec) {
  auto p1 = 0, p2 = 0, p4 = 0, p8 = 0;
  auto nbytes = avec.size() / 8;
  auto res = vector<int>(12 * nbytes);
  // para cada bit de verificação soma-se os bits de dados de acordo com a regra
  // e verifica-se a paridade cada bit é inserido no vetor resultado já na ordem
  for (auto i = 0; i < 8; i += 8) {
    p1 =
        (avec[i] + avec[i + 1] + avec[i + 3] + avec[i + 4] + avec[i + 6]) % 2 ==
                0
            ? 0
            : 1;
    res.push_back(p1);
    p2 =
        (avec[i] + avec[i + 2] + avec[i + 3] + avec[i + 5] + avec[i + 6]) % 2 ==
                0
            ? 0
            : 1;
    res.push_back(p2);
    res.push_back(avec[i]);
    p4 = (avec[i + 1] + avec[i + 2] + avec[i + 3] + avec[i + 7]) % 2 == 0 ? 0
                                                                          : 1;
    res.push_back(p4);
    res.insert(res.end(), avec.begin() + (i + 1), avec.begin() + (i + 3));
    p8 = (avec[i + 4] + avec[i + 5] + avec[i + 6] + avec[i + 7]) % 2 == 0 ? 0
                                                                          : 1;
    res.insert(res.end(), avec.begin() + (i + 4), avec.begin() + (i + 7));
  }

  return res;
}
// codigodehamminginverso1 confere se cada um dos bits de dados corresponde a
// soma de seus bits de verificação. A função acusa erro quando qualquer um
// deles não tem o valor que deveria.
bool codigodehamminginverso1(vector<int> avec) {
  auto m3 = 0, m5 = 0, m6 = 0, m7 = 0, m9 = 0, m10 = 0, m11 = 0, m12 = 0;
  auto soma = 0;
  for (auto i = 0; i < 8; i += 8) {
    m3 = (avec[i + 0] + avec[i + 1]) == avec[i + 2] ? 0 : 1;
    m5 = (avec[i + 3] + avec[i + 0]) == avec[i + 4] ? 0 : 1;
    m6 = (avec[i + 3] + avec[i + 1]) == avec[i + 5] ? 0 : 1;
    m7 = (avec[i + 3] + avec[i + 1] + avec[i + 0]) == avec[i + 6] ? 0 : 1;
    m9 = (avec[i + 7] + avec[i + 0]) == avec[i + 8] ? 0 : 1;
    m10 = (avec[i + 7] + avec[i + 1]) == avec[i + 9] ? 0 : 1;
    m11 = (avec[i + 7] + avec[i + 1] + avec[i + 0]) == avec[i + 10] ? 0 : 1;
    m12 = (avec[i + 7] + avec[i + 3]) == avec[i + 11] ? 0 : 1;
    soma = m3 + m5 + m7 + m9 + m10 + m11 + m12;

    if (soma != 8) {
      throw std::runtime_error(
          "a verificação do código de hamming detectou erro na transmissão");
    }
  }

  return true;
}

// codigodehamming formata os dados para facilitar operação e chama a função que
// realmente opera
int *codigodehamming(int *a, int len) {
  vector<int> avec;
  for (auto i = 0; i < len; i) {
    avec.push_back(a[i]);
  }
  std::vector<int> res = codigodehamming1(avec);
  return res.data();
}
// codigodehamminginverso formata os dados para facilitar operação e chama
// função que realmente opera
bool codigodehamminginverso(int *a, int len) {
  vector<int> avec;
  for (auto i = 0; i < len; i) {
    avec.push_back(a[i]);
  }
  bool res = codigodehamminginverso1(avec);
  return res;
}

int *entryfleu(int *a, int len) {
  vector<int> avec;
  for (auto i = 0; i < 8; i) {
    avec.push_back(a[i]);
  }
  return avec.data();
}
 */