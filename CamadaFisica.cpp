#include "CamadaFisica.h"

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
	// Assumindo que o clock inicia em 0 e adotada a convenção de G. E. Thomas.
    // Material que mais auxiliou a compreender a lógica manchester:
    // https://github.com/sdht0/manchester-encoding/blob/master/screenshot.jpg
    int quadroSize = sizeof(quadro)
    int manchester[2*quadroSize];

    for (int i = 0; i < quadroSize; i++) {
        manchester[2*i] = bitXnor(0, quadro[i])
        manchester[2*i +1] = bitXnor(1, quadro[i])
    }

    return manchester;
}

///////////////////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaTransmissoraCodificacaoManchesterDiferencial		//
/////////////////////////////////////////////////////////////////////////////
int[] CamadaFisicaTransmissoraCodificacaoManchesterDiferencial (int quadro []) {
	// Code
}

int bitXor(int a, int b) {
    return a^b;
}

}

int bitXnor(int a, int b) {
    return !(a^b);
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