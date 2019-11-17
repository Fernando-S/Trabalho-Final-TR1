#include "CamadaFisica.h"

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


///////////////////////////////////////////////
//		Metodo CamadaFisicaTransmissora		//
/////////////////////////////////////////////
void CamadaFisicaTransmissora (int quadro[]) {
	int tipoDeCodificacao = 0; //alterar de acordo o teste
	int fluxoBrutoDeBits []; //ATENÇÃO: trabalhar com BITS!!!
	
	switch (tipoDeCodificacao) {
		case 0 : //codificao binaria
			fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
			break;
		case 1 : //codificacao manchester
			fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
			break;
		case 2 : //codificacao manchester diferencial
			fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(quadro);
		break;
	}

	MeioDeComunicacao(fluxoBrutoDeBits);
}


///////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaTransmissoraCodificacaoBinaria		//
/////////////////////////////////////////////////////////////////
int[] CamadaFisicaTransmissoraCodificacaoBinaria (int quadro []) {
	//implementacao do algoritmo
}


///////////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaTransmissoraCodificacaoManchester		//
/////////////////////////////////////////////////////////////////////
int[] CamadaFisicaTransmissoraCodificacaoManchester (int quadro []) {
	//implementacao do algoritmo
}


///////////////////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaTransmissoraCodificacaoManchesterDiferencial		//
/////////////////////////////////////////////////////////////////////////////
int[] CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int quadro []){
	//implementacao do algoritmo
}


///////////////////////////////////////////
//		Metodo MeioDeTransmissao		//
/////////////////////////////////////////
/* Este metodo simula a transmissao da informacao no meio de
* comunicacao, passando de um pontoA (transmissor) para um
* ponto B (receptor)
*/
void MeioDeComunicacao (int fluxoBrutoDeBits []) {
    //OBS IMPORTANTE: trabalhar com BITS e nao com BYTES!!!
    int fluxoBrutoDeBitsPontoA[], fluxoBrutoDeBitsPontoB[];

    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;

    while (fluxoBrutoDeBitsPontoB.lenght != fluxoBrutoDeBitsPontoA) {
        fluxoBrutoBitsPontoB += fluxoBrutoBitsPontoA; //BITS! Sendo transferidos
    }
    //chama proxima camada
    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}


///////////////////////////////////////////////
//		Metodo CamadaFisicaTransmissora		//
/////////////////////////////////////////////
void CamadaFisicaReceptora (int quadro[]) {
    int tipoDeDecodificacao = 0; //alterar de acordo o teste
    int fluxoBrutoDeBits []; //ATENÇÃO: trabalhar com BITS!!!

    switch (tipoDeDecodificacao) {
        case 0 : //codificao binaria
            fluxoBrutoDeBits =
                    CamadaFisicaReceptoraDecodificacaoBinaria(quadro);
            break;
        case 1 : //codificacao manchester
            fluxoBrutoDeBits =
                    CamadaFisicaReceptoraDecodificacaoManchester(quadro);
            break;
        case 2 : //codificacao manchester diferencial
            fluxoBrutoDeBits =
                    CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(quadro);
            break;
    }
    //chama proxima camada
    CamadaDeAplicacaoReceptora(fluxoBrutoDeBits);
}


///////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaReceptoraDecodificacaoBinaria		//
/////////////////////////////////////////////////////////////////
int[] CamadaFisicaReceptoraCodificacaoBinaria (int quadro []) {
    //implementacao do algoritmo para DECODIFICAR
}


///////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaReceptoraDecodificacaoManchester		//
/////////////////////////////////////////////////////////////////
int[] CamadaFisicaReceptoraCodificacaoManchester (int quadro []) {
    //implementacao do algoritmo para DECODIFICAR
}


///////////////////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaReceptoraDecodificacaoManchesterDiferencial		//
/////////////////////////////////////////////////////////////////////////////
int[] CamadaFisicaReceptoraCodificacaoManchesterDiferencial(int quadro[]){
    //implementacao do algoritmo para DECODIFICAR
}


///////////////////////////////////////////////////
//		Metodo CamadaDeAplicacaoReceptora		//
/////////////////////////////////////////////////
void CamadaDeAplicacaoReceptora (int quadro []) {
    //string mensagem = quadro []; //estava trabalhando com bits
    //chama proxima camada
    AplicacaoReceptora(mensagem);
}


///////////////////////////////////////////
//		Metodo AplicacaoReceptora		//
/////////////////////////////////////////
void AplicacaoReceptora (string mensagem) {
    cout << "A mensagem recebida foi:" << mensagem << endl;
}