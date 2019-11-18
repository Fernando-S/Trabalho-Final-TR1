#include <iostream>

/*************************************************************
* NAO ESQUECER DOS COMENTARIOS!
*********************************************************** */

///////////////////////////
//		Metodo Main		//
/////////////////////////
void main (void) {
    AplicacaoTransmissora();
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


///////////////////////////////////////////////////
//		Metodo CamadaAplicacaoTransmissora		//
/////////////////////////////////////////////////
void CamadaDeAplicacaoTransmissora (string mensagem) {
    //int quadro [] = mensagem //trabalhar com bits!!!
    //chama a proxima camada
    CamadaFisicaTransmissora(quadro);
}
