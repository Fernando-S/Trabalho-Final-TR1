#include "CamadaEnlace.h"
/*
///////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissora        //
/////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissora (int quadro []) {
    //algum codigo aqui
}


/////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraEnquadramentos        //
///////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraEnquadramento (int quadro []) {
    //algum codigo aqui
}


/////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraControleDeErro        //
///////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraControleDeErro (int quadro []) {
    //algum codigo aqui
}


//////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraControleDeFluxo        //
////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraControleDeFluxo (int quadro []) {
    //algum codigo aqui
}


///////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissora        //
/////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissora (int quadro []) {
    CamadaDeEnlaceTransmissoraEnquadramento(quadro);
    CamadaDeEnlaceTransmissoraControleDeErro(quadro);
    CamadaDeEnlaceTransmissoraControleDeFluxo(quadro);

    //chama proxima camada
    CamadaFisicaTransmissora(quadro);
}


///////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceTransmissoraEnquadramento        //
/////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraEnquadramento (int quadro []) {
    int tipoDeEnquadramento= 0; //alterar de acordo com o teste
    int quadroEnquadrado [];

    switch (tipoDeEnquadramento) {
        case 0 : //contagem de caracteres
            quadroEnquadrado = CamadaDeEnlaceTransmissoraEnquadramentoContagemDeCaracteres(quadro);
            break;
        case 1 : //insercao de bytes
            quadroEnquadrado = CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBytes(quadro);
            break;
        case 2 : //insercao de bits
            quadroEnquadrado = CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBits(quadro);
        case 3 : //violacao da camada fisica
            quadroEnquadrado = CamadaDeEnlaceTransmissoraEnquadramentoViolacaoCamadaFisica(quadro);
            break;
    }
}


///////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraContagemDeCaracteres        //
/////////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres (int quadro []) {
    //implementacao do algoritmo
}


//////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraInsercaoDeBytes        //
////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes (int quadro []) {
    //implementacao do algoritmo
}


/////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraInsercaoDeBits        //
///////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBits (int quadro []) {
    //implementacao do algoritmo
}


/////////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraViolacaoDaCamadaFisica        //
///////////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraEnquadramentoViolacaoDaCamadaFisica (int quadro []) {
    //implementacao do algoritmo
}


////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptora        //
//////////////////////////////////////////////////
void CamadaEnlaceDadosReceptora (int quadro []) {
    //algum codigo aqui
}


/////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraEnquadramento        //
///////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraEnquadramento (int quadro []) {
    //algum codigo aqui
}


//////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraControleDeErro        //
////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraControleDeErro (int quadro []) {
    //algum codigo aqui
}


///////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraControleDeFluxo        //
/////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraControleDeFluxo (int quadro []) {
    //algum codigo aqui
}


////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptora        //
//////////////////////////////////////////////////
void CamadaEnlaceDadosReceptora (int quadro []) {
    CamadaDeEnlaceTransmissoraEnquadramento(quadro);
    CamadaDeEnlaceTransmissoraControleDeErro(quadro);
    CamadaDeEnlaceTransmissoraControleDeFluxo(quadro);

    //chama proxima camada
    CamadaDeAplicacaoReceptora(quadro);
}


/////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraEnquadramento        //
///////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraEnquadramento (int quadro []) {
    int tipoDeEnquadramento= 0; //alterar de acordo com o teste
    int quadroDesenquadrado [];

    switch (tipoDeEnquadramento) {
        case 0 : //contagem de caracteres
            quadroDesenquadrado = CamadaDeEnlaceTransmissoraEnquadramentoContagemDeCaracteres(quadro);
            break;
        case 1 : //insercao de bytes
            quadroDesenquadrado = CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBytes(quadro);
            break;
        case 2 : //insercao de bits
            quadroDesenquadrado = CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBits(quadro);
        case 3 : //violacao da camada fisica
            quadroDesenquadrado = CamadaDeEnlaceTransmissoraEnquadramentoViolacaoCamadaFisica(quadro);
            break;
    }
}


////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraContagemDeCaracteres        //
//////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres (int quadro []) {
    //implementacao do algoritmo para DESENQUADRAR
}


///////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraInsercaoDeBytes        //
/////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes (int quadro []) {
    //implementacao do algoritmo para DESENQUADRAR
}


//////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraInsercaoDeBits        //
////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBits (int quadro[]) {
    //implementacao do algoritmo para DESENQUADRAR
}


//////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraViolacaoDaCamadaFisica        //
////////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraEnquadramentoViolacaoDaCamadaFisica(int quadro []) {
    //implementacao do algoritmo para DESENQUADRAR
}


///////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissora        //
/////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissora (int quadro []) {
    //algum codigo aqui
}


/////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraEnquadramentos        //
///////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraEnquadramento (int quadro []) {
    //algum codigo aqui
}


/////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraControleDeErro        //
///////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraControleDeErro (int quadro []) {
    //algum codigo aqui
}


//////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraControleDeFluxo        //
////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraControleDeFluxo (int quadro []) {
    //algum codigo aqui
}


///////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissora        //
/////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissora (int quadro []) {
    CamadaEnlaceDadosTransmissoraEnquadramento(quadro);
    CamadaEnlaceDadosTransmissoraControleDeErro(quadro);
    CamadaEnlaceDadosTransmissoraControleDeFluxo(quadro);

    //chama proxima camada
    CamadaFisicaTransmissora(quadro);
}


/////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraControleDeErro        //
///////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraControleDeErro (int quadro []) {
    int tipoDeControleDeErro = 0; //alterar de acordo com o teste

    switch (tipoDeControleDeErro) {
        case 0 : //bit de paridade par
            //codigo
            break;
        case 1 : //bit de paridade impar
            //codigo
            break;
        case 2 : //CRC
            //codigo
        case 3 : //codigo de Hamming
            //codigo
            break;
    }
}


///////////////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraControledeErroBitParidadePar        //
/////////////////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar (int quadro []) {
    //implementacao do algoritmo
}


/////////////////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraControledeErroBitParidadeImpar        //
///////////////////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar (int quadro []) {
    //implementacao do algoritmo
}


////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraControledeErroCRC        //
//////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraControleDeErroCRC (int quadro []) {
    //implementacao do algoritmo
    //usar polinomio CRC-32(IEEE 802)
}


////////////////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraControleDeErroCodigoDehamming        //
//////////////////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming (int quadro []) {
    //implementacao do algoritmo
}


///////////////////////////////////////////
//      Metodo MeioDeTransmissao        //
/////////////////////////////////////////
void MeioDeComunicacao (int fluxoBrutoDeBits []) {
    //OBS: trabalhar com BITS e nao com BYTES!!!
    int erro, porcentagemDeErros;
    int fluxoBrutoDeBitsPontoA [], fluxoBrutoDeBitsPontoB [];

    porcentagemDeErros = 0; //10%, 20%, 30%, 40%, ..., 100%
    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;

    while (fluxoBrutoDeBitsPontoB.lenght != fluxoBrutoDeBitsPontoA) {
        if ((rand()%100)== ... ) //fazer a probabilidade do erro
        fluxoBrutoBitsPontoB += fluxoBrutoBitsPontoA; //BITS!!!
        else //ERRO! INVERTER (usa condicao ternaria)
        fluxoBrutoBitsPontoB==0) ?
        fluxoBrutoBitsPontoA=fluxoBrutoBitsPontoB++ :
        fluxoBrutoBitsPontoA=fluxoBrutoBitsPontoB--;
    }
}


///////////////////////////////////////////////
//      Metodo CamadaEnlaceReceptora        //
/////////////////////////////////////////////
void CamadaEnlaceDadosReceptora ( int quadro []) {
    //algum codigo aqui
}


/////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraEnquadramento        //
///////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraEnquadramento ( int quadro []) {
    //algum codigo aqui
}


//////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraControleDeErro        //
////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraControleDeErro ( int quadro []) {
    //algum codigo aqui
}


///////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraControleDeFluxo        //
/////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraControleDeFluxo ( int quadro []) {
    //algum codigo aqui
}


////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptora        //
//////////////////////////////////////////////////
void CamadaEnlaceDadosReceptora (int quadro []) {
    CamadaDeEnlaceTransmissoraEnquadramento(quadro);
    CamadaDeEnlaceTransmissoraControleDeErro(quadro);
    CamadaDeEnlaceTransmissoraControleDeFluxo(quadro);

    //chama proxima camada
    CamadaDeAplicacaoReceptora(quadro);
}


//////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraControleDeErro        //
////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraControleDeErro (int quadro []) {
    int tipoDeControleDeErro = 0; //alterar de acordo com o teste

    switch (tipoDeControleDeErro) {
        case 0 : //bit de paridade par
            //codigo
            break;
        case 1 : //bit de paridade impar
            //codigo
            break;
        case 2 : //CRC
            //codigo
        case 3 : //codigo de hamming
            //codigo
            break;
    }
}


//////////////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadePar        //
////////////////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadePar (int quadro []) {
    //implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
}


////////////////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadeImpar        //
//////////////////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadeImpar (int quadro []) {
    //implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
}


/////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraControleDeErroCRC        //
///////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraControleDeErroCRC (int quadro []) {
    //implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
    //usar polinomio CRC-32(IEEE 802)
}


/////////////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming        //
///////////////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming (int quadro []) {
    //implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
}
 */