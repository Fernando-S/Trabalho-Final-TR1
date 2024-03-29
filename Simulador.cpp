#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include "CamadaFisica.h"
#include "CamadaEnlace.h"
#include "Simulador.h"
#include <time.h>
#include <stdlib.h>

int TIPO_ENQUADRAMENTO = 0;

using namespace std;

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
        if(i == 6){
          quadro_invertido[i] = 0;
          i++;
        }
        if(i == 5){
          for(i = 5; i<8; i++)
            quadro_invertido[i] = 0;
        }
        if(i == 4){
          for(i = 4; i<8; i++)
            quadro_invertido[i] = 0;
        }
        if(i == 3){
          for(i = 3; i<8; i++)
            quadro_invertido[i] = 0;
        }
        if(i == 2){
          for(i = 2; i<8; i++)
            quadro_invertido[i] = 0;
        }
        if(i == 1){
          for(i = 1; i<8; i++)
            quadro_invertido[i] = 0;
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

  CamadaEnlaceDadosTransmissora(quadro,size);
//    CamadaFisicaTransmissora(quadro, size);
}


///////////////////////////////////////////////
//		Metodo AplicacaoTransmissora		//
/////////////////////////////////////////////
void AplicacaoTransmissora (void) {
    string mensagem;

    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);
    cout << endl;

    //chama a proxima camada
    CamadaDeAplicacaoTransmissora(mensagem); //em um exemplo mais realistico, aqui seria dado um SEND do SOCKET
}


///////////////////////////////////////////////////
//		Metodo CamadaDeAplicacaoReceptora		//
/////////////////////////////////////////////////
void CamadaDeAplicacaoReceptora (int quadro [], int size) {

    string mensagem = binarioparastring(quadro, size);
    AplicacaoReceptora(mensagem);
}


///////////////////////////////////////////
//		Metodo AplicacaoReceptora		//
/////////////////////////////////////////
void AplicacaoReceptora (string mensagem) {
    cout << "A mensagem recebida foi: " << mensagem << endl;
}


///////////////////////////////////////////////////////
//      Metodo de Traducao de Bits para Ascii       //
/////////////////////////////////////////////////////
string binarioparastring(int *vetor, int size) {
    int k, c, j = 0;
    uint i = 0;

    std::vector<char> ret;
    for (c = 0; c < size; c += 7) {
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
int main (void) {
    AplicacaoTransmissora();
    return 0;
}
