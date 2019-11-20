/*###################################################################
# Universidade de Brasilia                                          #
#      Teleinformatica e Redes 1 - Trabalho Final                   #
#                                                                   #
#           Alunos                                  Matriculas      #
#                                                                   #
#   Fernando Sobral Nobrega                         15/0034911      #
#   Aécio Fernandes Galiza Magalhães	            15/0115121      #
#   Guilherme Fleury Franco	        	            18/0121472	    #
#   Nícolas Machado Schumacher      	            13/0047660      #
#                                                                   #
#            Compilador e Sistema Operacional usados                #
#           g++ (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0               #
#                                                                   #
###################################################################*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include "CamadaFisica.h"
#include "CamadaEnlace.h"

using namespace std;

/*************************************************************
* NAO ESQUECER DOS COMENTARIOS!
*********************************************************** */
///////////////////////////////////////////////////
//		Metodo CamadaAplicacaoTransmissora		//
/////////////////////////////////////////////////
void CamadaDeAplicacaoTransmissora (string mensagem, int escolha) {
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

    switch (escolha){
        case 1:
            CamadaFisicaTransmissora(quadro, size);
            break;
        case 2:
            CamadaEnlaceDadosTransmissora(quadro,size);
            break;
    }
}


///////////////////////////////////////////////
//		Metodo AplicacaoTransmissora		//
/////////////////////////////////////////////
void AplicacaoTransmissora (void) {
    string mensagem;
    int escolha;

    cout << "Por favor, informe qual camada deseja simular (1 - Camada Fisica e 2 - Cama de Enlace): ";
    cin >> escolha;
    while(escolha != 1 && escolha != 2){
        cout << "Opcao invalida! Informe qual camada deseja simular (1 - Camada Fisica e 2 - Cama de Enlace): ";
        cin >> escolha;
    }
    getchar();

    cout << "Digite uma mensagem:" << endl;
    getline(cin, mensagem);

    //chama a proxima camada
    CamadaDeAplicacaoTransmissora(mensagem, escolha); //em um exemplo mais realistico, aqui seria dado um SEND do SOCKET
}

///////////////////////////
//		Metodo Main		//
/////////////////////////
int main (void) {
    AplicacaoTransmissora();
    return 0;
}
