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


///////////////////////////
//		Metodo Main		//
/////////////////////////
int main (void) {

    AplicacaoTransmissora();

    return 0;
}


