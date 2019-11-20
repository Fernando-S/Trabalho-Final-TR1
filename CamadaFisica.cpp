#include "CamadaFisica.h"

using namespace std;
///////////////////////////////////////////////
//		Metodo CamadaFisicaTransmissora		//
/////////////////////////////////////////////
void CamadaFisicaTransmissora (int quadro[], int size) {
	int tipoDeCodificacao; //alterar de acordo o teste

    cout << "Por favor, informe qual codificacao deseja (1 - Binaria, 2 - Manchester, 3 Manchester Diferencial: ";
    cin >> tipoDeCodificacao;

    while(tipoDeCodificacao != 1 && tipoDeCodificacao != 2 && tipoDeCodificacao != 3){
        cout << "Opcao invalida!" << endl;
        cout << "Por favor, informe qual codificacao deseja (1 - Binaria, 2 - Manchester, 3 Manchester Diferencial: ";
        cin >> tipoDeCodificacao;
    }
    tipoDeCodificacao--;

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
}


///////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaTransmissoraCodificacaoBinaria		//
/////////////////////////////////////////////////////////////////
void CamadaFisicaTransmissoraCodificacaoBinaria (int quadro [], int size) {
    MeioDeComunicacao(quadro, size, 0);
}


///////////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaTransmissoraCodificacaoManchester		//
/////////////////////////////////////////////////////////////////////
void CamadaFisicaTransmissoraCodificacaoManchester (int* quadro, int size) {
	// Assumindo que o clock inicia em 0 e adotada a convenção de G. E. Thomas.
    // Material que mais auxiliou a compreender a lógica manchester:
    // https://github.com/sdht0/manchester-encoding/blob/master/screenshot.jpg
    int i;
    int manchester[2*size];

    for (i = 0; i < size; i++) {
        manchester[2*i] = bitXnor(0, quadro[i]);
        manchester[2*i +1] = bitXnor(1, quadro[i]);
    }

    cout << "O fluxo de bits apos a codificacao manchester eh: ";
    for (i=0; i< 2*size; i++){
        cout << manchester[i];
    }

    cout << endl;

    MeioDeComunicacao(manchester, 2*size, 1);
}


///////////////////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaTransmissoraCodificacaoManchesterDiferencial		//
/////////////////////////////////////////////////////////////////////////////
void CamadaFisicaTransmissoraCodificacaoManchesterDiferencial (int quadro[], int size) {
	// Assumindo que o clock inicia em 0
    int manchesterD[2*size], i;
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

    cout << "O fluxo de bits apos a codificacao manchester diferencial eh: ";
    for(i=0; i< 2*size; i++){
        cout << manchesterD[i];
    }
    cout << endl;

	MeioDeComunicacao(manchesterD, 2*size, 2);
}


///////////////////////////////////////////////////
//      Metodo para Operacao Xnor de Bits       //
/////////////////////////////////////////////////
int bitXnor(int a, int b) {
    return !(a^b);
}


///////////////////////////////////////////
//		Metodo MeioDeTransmissao		//
/////////////////////////////////////////
// Este metodo simula a transmissao da informacao no meio de
// comunicacao, passando de um pontoA (transmissor) para um
// ponto B (receptor)
void MeioDeComunicacao (int fluxoBrutoDeBits[], int size, int tipoDeDecodificacao) {
    int fluxoBrutoDeBitsPontoA[size], fluxoBrutoDeBitsPontoB[size], i;

    cout << "O fluxo de bits que parte do ponto A eh: ";
    for(i=0; i<size; i++){
       fluxoBrutoDeBitsPontoA[i] = fluxoBrutoDeBits[i];
         cout << fluxoBrutoDeBitsPontoA[i];
    }
    cout << endl;

    cout << "O fluxo de bits que chega no ponto B eh: ";
    for(i = 0; i< size; i++) {
        fluxoBrutoDeBitsPontoB[i] = fluxoBrutoDeBitsPontoA[i];
        cout << fluxoBrutoDeBitsPontoB[i];//BITS! Sendo transferidos
    }
    cout << endl;

    //chama proxima camada
    switch (tipoDeDecodificacao){
        case 0:
            CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB, size, tipoDeDecodificacao);
            break;
        case 1:
            CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB, size, tipoDeDecodificacao);
            break;
        case 2:
            CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB, size/2, tipoDeDecodificacao);
            break;
    }
}


///////////////////////////////////////////////
//		Metodo CamadaFisicaTransmissora		//
/////////////////////////////////////////////
void CamadaFisicaReceptora (int quadro[], int size, int tipoDeDecodificacao) {

    switch (tipoDeDecodificacao) {
        case 0 : //codificao binaria
            CamadaFisicaReceptoraDecodificacaoBinaria(quadro, size);
            break;
        case 1 : //codificacao manchester
            CamadaFisicaReceptoraDecodificacaoManchester(quadro, size);
            break;
        case 2 : //codificacao manchester diferencial
            CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(quadro, size);
            break;
    }
}


///////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaReceptoraDecodificacaoBinaria		//
/////////////////////////////////////////////////////////////////
void CamadaFisicaReceptoraDecodificacaoBinaria (int quadro[], int size) {
    CamadaDeAplicacaoReceptora(quadro, size);
}


///////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaReceptoraDecodificacaoManchester		//
/////////////////////////////////////////////////////////////////
void CamadaFisicaReceptoraDecodificacaoManchester (int* manchester, int manchester_size) {
	// Assumindo que o clock inicia em 0 e adotada a convenção de G. E. Thomas.
    int quadro[manchester_size/2];

    for (int i = 0; i < manchester_size/2; i++) {
        quadro[i] = bitXnor(manchester[2*i], 0);
    }

    cout << "\nO quadro decodificado eh: ";
    for (int i= 0; i< manchester_size/2; i++){
        cout << quadro[i];
    }
    cout << endl;

    CamadaDeAplicacaoReceptora(quadro, manchester_size/2);
}


///////////////////////////////////////////////////////////////////////////////
//		Metodo CamadaFisicaReceptoraDecodificacaoManchesterDiferencial		//
/////////////////////////////////////////////////////////////////////////////
void CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(int quadro[], int size){
	int clk[2*size], quadroDecod[size], i;
	int bitAnterior = 1; //bit antes do começo da análise do quadro para codificação

	for(i = 0; i<size; i++){  //mapeia um clock igual ao utilizado para codificar
		 clk[2*i] = 0;
		 clk[2*i + 1] = 1;
	}

    //implementacao do algoritmo para DECODIFICAR
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

    CamadaDeAplicacaoReceptora(quadroDecod, size);
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

