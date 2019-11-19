#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

/*************************************************************
* NAO ESQUECER DOS COMENTARIOS!
*********************************************************** */

/////////////////////////////////////////////
//    Metodo ConversorDecimalBinario      //
///////////////////////////////////////////
int* ConversorDecimalBinario (string msg) {
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

    int *ptr;
    ptr = &quadro[0];
/*    for (m = 0; m < size; m++){
      cout << ptr[m];
    }
*/
    return ptr;
    // todo - pensar em como retornar o array
//        return *quadro;
}

///////////////////////////////////////////////////
//		Metodo CamadaAplicacaoTransmissora		//
/////////////////////////////////////////////////
void CamadaDeAplicacaoTransmissora (string mensagem) {
    //int quadro [] = mensagem //trabalhar com bits!!!
    //chama a proxima camada
    int m, *ptr = ConversorDecimalBinario(mensagem);
    for (m = 0; ptr[m] != '\0' ; m++){
      cout << ptr[m];
    }


    //CamadaFisicaTransmissora(quadro);
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
