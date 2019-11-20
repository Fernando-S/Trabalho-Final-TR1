#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include "CamadaFisica.h"

using namespace std;

/*************************************************************
* NAO ESQUECER DOS COMENTARIOS!
*********************************************************** */
///////////////////////////////////////////////////
//		Metodo CamadaAplicacaoTransmissora		//
/////////////////////////////////////////////////
void CamadaDeAplicacaoTransmissora (string mensagem) {
    int n = mensagem.size();
    int i = 0, m = 0, size = 0, msg[n];
    int quadro_invertido[n*7], quadro[n*7];

    for (i = 0; i < n; i++){
        msg[i] = mensagem[i];
    }

    i=0;

    int o = 0, soma = 0;

    for(m = 0; m < n; m++){
        i = 0;
        while(msg[m] > 0){
            quadro_invertido[i] = msg[m]%2;
            msg[m] /= 2;
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

    CamadaFisicaTransmissora(quadro, size);
}


///////////////////////////////////////////////
//		Metodo AplicacaoTransmissora		//
/////////////////////////////////////////////
void AplicacaoTransmissora (void) {
    string mensagem;

    cout << "Digite uma mensagem:" << endl;
    cin >> mensagem;

    //chama a proxima camada
    CamadaDeAplicacaoTransmissora(mensagem); //em um exemplo mais realistico, aqui seria dado um SEND do SOCKET
}



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
    cout << binarioparastring(a, 4) << endl;
    char b = 94;
    cout << b << endl;

    AplicacaoTransmissora();
    return 0;
}


