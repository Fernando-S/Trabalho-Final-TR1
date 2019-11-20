#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include "CamadaFisica.h"

using namespace std;

string binarioparastring(int* vetor, int n) {
    int k, c, i = 0, j = 0;
    char retorno[n / 8];

    for (c = 0; c < n; c += 8) {
        j = 0;
        for (k = 0; k < 8; k++) {
            i = (vetor[n] * 128) + (vetor[n + 1] * 64) + (vetor[n + 2] * 32) +
                (vetor[n + 3] * 16) + (vetor[n + 4] * 8) + (vetor[n + 5] * 4) + (vetor[n + 6] * 2) + (vetor[n + 7] * 1);
            retorno[j] = i;
            j++;
        }
    }

    return retorno;
}

///////////////////////////
//		Metodo Main		//
/////////////////////////
int main (void) {
    int a[8] = {0,0,0,0,0,0,0,1};
    char b = 94;
    char c[3] = {97, 97, 97};
    string d = binarioparastring(a, 8);
    char* e;

    for(int i = 0; i < 8; i++){
        cout << d[i] << endl;
//        e[i] = d[i];  isso aqui da segmentation fault
    }

    cout << "d eh: " << d << endl;
    cout << "b eh: "  << b << endl;
    cout << "c eh: "  << c << endl;
    cout << "e eh: "  << e << endl;

    return 0;
}


