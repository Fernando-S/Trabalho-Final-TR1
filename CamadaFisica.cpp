#include "CamadaFisica.h"
#include <iostream>

using namespace std;
///////////////////////////////////////////////
//		Metodo CamadaFisicaTransmissora		//
/////////////////////////////////////////////
void CamadaFisicaTransmissora (int quadro[], int size) {
	int tipoDeCodificacao = 0; //alterar de acordo o teste
//	int* fluxoBrutoDeBits; //ATENÇÃO: trabalhar com BITS!!!

	cout << "O quadro enviado apos traducao para bits eh: ";

    for (int m = 0; m < size; m++){
        cout << quadro[m];
    }  //  o for comentado testa a saida do ponteiro

    cout << endl;


	switch (tipoDeCodificacao) {
		case 0 : //codificao binaria
		    CamadaFisicaTransmissoraCodificacaoBinaria(quadro, size);
			break;
		case 1 : //codificacao manchester
			CamadaFisicaTransmissoraCodificacaoManchester(quadro, size);
			break;
		case 2 : //codificacao manchester diferencial
			CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(quadro, size);
		break;
	}

//	MeioDeComunicacao(fluxoBrutoDeBits, size);
}


///////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaTransmissoraCodificacaoBinaria		//
/////////////////////////////////////////////////////////////////
void CamadaFisicaTransmissoraCodificacaoBinaria (int quadro [], int size) {
	//implementacao do algoritmo
//    int i;
//    todo - dar um jeito de poder usar o size
//    static int array[size];
//
//    for(i = 0; i < size; i++){
//       array[i] = quadro[i];
//    }

    // exemplo generico
//    static int array[3] = {1,2,3};
//    return array;
    MeioDeComunicacao(quadro, size);
}


///////////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaTransmissoraCodificacaoManchester		//
/////////////////////////////////////////////////////////////////////
void CamadaFisicaTransmissoraCodificacaoManchester (int* quadro, int size, int* manchester) {
	// Assumindo que o clock inicia em 0 e adotada a convenção de G. E. Thomas.
    // Material que mais auxiliou a compreender a lógica manchester:
    // https://github.com/sdht0/manchester-encoding/blob/master/screenshot.jpg
    for (int i = 0; i < size; i++) {
        manchester[2*i] = bitXnor(0, quadro[i]);
        manchester[2*i +1] = bitXnor(1, quadro[i]);
    }
}


///////////////////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaTransmissoraCodificacaoManchesterDiferencial		//
/////////////////////////////////////////////////////////////////////////////
void CamadaFisicaTransmissoraCodificacaoManchesterDiferencial (int quadro[], int size) {
	// Assumindo que o clock inicia em 0
    int manchesterD[2*size];
    int i;
    int bitAnterior = 1; //bit antes do começo da análise do quadro para codificação
    for(i = 0; i<size; i++){
        manchesterD[2*i] = 0;        //vai ser inicialmente o clock, para fazer as modificações em cima desse vetor
        manchesterD[2*i + 1] = 1;
    }

	for (i=0; i<size; i++){
        if(i == 0){
            if(quadro[0] == 1){
                manchesterD[2*i] = bitAnterior;
                manchesterD[2*i + 1] ^= manchesterD[2*i];
            }
            else if (quadro[0] == 0){
                manchesterD[2*1] ^= bitAnterior;
                manchesterD[2*i + 1] ^= manchesterD[2*i];
            }
        }
        else{
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
    }

    cout << "O fluxo de bits apos a codificacao manchester eh: ";
    for(i=0; i< 2*size; i++){
        cout << manchesterD[i];
    }
    cout << endl;

	MeioDeComunicacao(manchesterD, 2*size);
}

/*

int bitXor(int a, int b) {
    return a^b;
}

}
*/

int bitXnor(int a, int b) {
    return !(a^b);
}

///////////////////////////////////////////
//		Metodo MeioDeTransmissao		//
/////////////////////////////////////////
// Este metodo simula a transmissao da informacao no meio de
// comunicacao, passando de um pontoA (transmissor) para um
// ponto B (receptor)
void MeioDeComunicacao (int fluxoBrutoDeBits[], int size) {
    //OBS IMPORTANTE: trabalhar com BITS e nao com BYTES!!!

//    if(codificacao != 0){
//        size *= 2;
//    }


    int fluxoBrutoDeBitsPontoA[size], fluxoBrutoDeBitsPontoB[size];
    int i;
    cout << "O fluxo de bits que parte do ponto A eh: ";
    for(i=0; i<size; i++){
       fluxoBrutoDeBitsPontoA[i] = fluxoBrutoDeBits[i];
			 cout << fluxoBrutoDeBitsPontoA[i];
    }
		cout << endl;
//    while (fluxoBrutoDeBitsPontoB.lenght != fluxoBrutoDeBitsPontoA) {
//        fluxoBrutoDeBitsPontoB[i] += fluxoBrutoDeBitsPontoA[i]; //BITS! Sendo transferidos
//    }

		cout << "O fluxo de bits que chega no ponto B eh: ";
    for(i = 0; i< size; i++) {
        fluxoBrutoDeBitsPontoB[i] = fluxoBrutoDeBitsPontoA[i];
        cout << fluxoBrutoDeBitsPontoB[i];//BITS! Sendo transferidos
    }
		cout << endl;
    //chama proxima camada
    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB, size);
}


///////////////////////////////////////////////
//		Metodo CamadaFisicaTransmissora		//
/////////////////////////////////////////////
void CamadaFisicaReceptora (int quadro[], int size) {
    int tipoDeDecodificacao = 2; //alterar de acordo o teste
//    int* fluxoBrutoDeBits; //ATENÇÃO: trabalhar com BITS!!!
//		cout << "chegou";
    //todo - fazer a decodificacao
    switch (tipoDeDecodificacao) {
        case 0 : //codificao binaria
//            fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoBinaria(quadro);
            break;
        case 1 : //codificacao manchester
//            fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoManchester(quadro);
            break;
        case 2 : //codificacao manchester diferencial
//            fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(quadro, size);
            break;
    }
//    //chama proxima camada
//    CamadaDeAplicacaoReceptora(fluxoBrutoDeBits);

    cout << "Print apenas para ver se chega aqui" << endl;


}


///////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaReceptoraDecodificacaoBinaria		//
/////////////////////////////////////////////////////////////////
int* CamadaFisicaReceptoraCodificacaoBinaria (int quadro []) {
    //implementacao do algoritmo para DECODIFICAR
}


///////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaReceptoraDecodificacaoManchester		//
/////////////////////////////////////////////////////////////////
void CamadaFisicaReceptoraDecodificacaoManchester (int* manchester, int size, int* quadro) {
	// Assumindo que o clock inicia em 0 e adotada a convenção de G. E. Thomas.
    for (int i = 0; i < size/2; i++) {
        quadro[i] = bitXnor(manchester[2*i], 0);
    }
}


///////////////////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaReceptoraDecodificacaoManchesterDiferencial		//
/////////////////////////////////////////////////////////////////////////////
void CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(int quadro[], int size){
	int clk[2*size];
	int bitAnterior = 1;
	int i;
	for(i = 0; i<size; i++){  //mapeia um clock igual ao utilizado para codificar
		 clk[2*i] = 0;
		 clk[2*i + 1] = 1;
	}
		//implementacao do algoritmo para DECODIFICAR
	int quadroDecod[size];
	cout << "O quadro decodificado eh: ";
	for(i=0; i<size; i++){
		if(i == 0){
			if(quadro[0] == bitAnterior){
				quadroDecod[0] = 1;
			}
			else if (quadro[0] != bitAnterior){
				quadroDecod[0] = 0;
			}
		}
		else{
			if(quadro[2*i] == quadro[2*i - 1])
				quadroDecod[i] = 1;
			else
				quadroDecod[i] = 0;
		}
		cout << quadroDecod[i];
	}
	cout << endl;
}


///////////////////////////////////////////////////
//		Metodo CamadaDeAplicacaoReceptora		//
/////////////////////////////////////////////////
void CamadaDeAplicacaoReceptora (int quadro [], int size) {
    //string mensagem = quadro []; //estava trabalhando com bits
    //chama proxima camada

    // todo - decodificacao eh aqui

    //AplicacaoReceptora(mensagem);
}


///////////////////////////////////////////
//		Metodo AplicacaoReceptora		//
/////////////////////////////////////////
void AplicacaoReceptora (string mensagem) {
    cout << "A mensagem recebida foi:" << mensagem << endl;
}

