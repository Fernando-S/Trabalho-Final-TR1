#include "CamadaEnlace.h"
#include "iostream"
#include "vector"
/*
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


///////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceTransmissoraEnquadramento        //
/////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraEnquadramento (int quadro []) {
    int tipoDeEnquadramento= 0; //alterar de acordo com o teste
    int quadroEnquadrado [];

    switch (tipoDeEnquadramento) {
        case 0 : //contagem de caracteres
            quadroEnquadrado =
CamadaDeEnlaceTransmissoraEnquadramentoContagemDeCaracteres(quadro); break; case
1 : //insercao de bytes quadroEnquadrado =
CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBytes(quadro); break; case 2 :
//insercao de bits quadroEnquadrado =
CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBits(quadro); case 3 :
//violacao da camada fisica quadroEnquadrado =
CamadaDeEnlaceTransmissoraEnquadramentoViolacaoCamadaFisica(quadro); break;
    }
}


///////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraContagemDeCaracteres        //
/////////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres (int quadro
[]) {
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
void CamadaEnlaceDadosTransmissoraEnquadramentoViolacaoDaCamadaFisica (int
quadro []) {
    //implementacao do algoritmo
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
            quadroDesenquadrado =
CamadaDeEnlaceTransmissoraEnquadramentoContagemDeCaracteres(quadro); break; case
1 : //insercao de bytes quadroDesenquadrado =
CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBytes(quadro); break; case 2 :
//insercao de bits quadroDesenquadrado =
CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBits(quadro); case 3 :
//violacao da camada fisica quadroDesenquadrado =
CamadaDeEnlaceTransmissoraEnquadramentoViolacaoCamadaFisica(quadro); break;
    }
}


////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraContagemDeCaracteres        //
//////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres (int quadro [])
{
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
void CamadaEnlaceDadosReceptoraEnquadramentoViolacaoDaCamadaFisica(int quadro
[]) {
    //implementacao do algoritmo para DESENQUADRAR
}


//////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraControleDeFluxo        //
////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraControleDeFluxo (int quadro []) {
    //algum codigo aqui
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
//      Metodo CamadaEnlaceDadosTransmissoraControledeErroBitParidadePar //
/////////////////////////////////////////////////////////////////////////////////
int CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(int quadro[], int
size) {
    // Retorna o valor do bit de paridade que deve ser concatenado ao quadro
    int bitParidade = 0;

    for(int i = 0; i < size; i++) {
        bitParidade ^= quadro[i];
    }
    return bitParidazde;
}


/////////////////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraControledeErroBitParidadeImpar //
///////////////////////////////////////////////////////////////////////////////////
int CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(int quadro[],
int size) {
    // Retorna o valor do bit de paridade que deve ser concatenado ao quadro
    return ! CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(quadro,
size);
}


////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraControledeErroCRC        //
//////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraControleDeErroCRC (int quadro []) {
    //implementacao do algoritmo
    //usar polinomio CRC-32(IEEE 802)
}

*
////////////////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraControleDeErroCodigoDehamming //
//////////////////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming(int quadro[x]) {
  std::vector<int> avec;
  for (auto i = 0; i < x; i++) {
    avec.push_back(quadro[i]);
  }
  auto p1 = 0, p2 = 0, p4 = 0, p8 = 0;
  auto nbytes = avec.size() / 8;
  auto res = std::vector<int>(12 * nbytes);
  // para cada bit de verificação soma-se os bits de dados de acordo com a regra
  // e verifica-se a paridade cada bit é inserido no vetor resultado já na ordem
  for (auto i = 0; i < 8; i += 8) {
    p1 =
        (avec[i] + avec[i + 1] + avec[i + 3] + avec[i + 4] + avec[i + 6]) % 2 ==
                0
            ? 0
            : 1;
    res.push_back(p1);
    p2 =
        (avec[i] + avec[i + 2] + avec[i + 3] + avec[i + 5] + avec[i + 6]) % 2 ==
                0
            ? 0
            : 1;
    res.push_back(p2);
    res.push_back(avec[i]);
    p4 = (avec[i + 1] + avec[i + 2] + avec[i + 3] + avec[i + 7]) % 2 == 0 ? 0
                                                                          : 1;
    res.push_back(p4);
    res.insert(res.end(), avec.begin() + (i + 1), avec.begin() + (i + 3));
    p8 = (avec[i + 4] + avec[i + 5] + avec[i + 6] + avec[i + 7]) % 2 == 0 ? 0
                                                                          : 1;
    res.insert(res.end(), avec.begin() + (i + 4), avec.begin() + (i + 7));
  }
  std::cout << "o dado tratado pelo codigo de hamming é:";
  for (auto r : res) {
    std::cout << r << " " << std::endl;
  }

  std::cout << std::endl;
}

///////////////////////////////////////////
//      Metodo MeioDeTransmissao        //
/////////////////////////////////////////
void MeioDeComunicacao(int fluxoBrutoDeBits[]) {
  // OBS: trabalhar com BITS e nao com BYTES!!!
  int erro, porcentagemDeErros;
  int fluxoBrutoDeBitsPontoA[], fluxoBrutoDeBitsPontoB[];

  porcentagemDeErros = 0; // 10%, 20%, 30%, 40%, ..., 100%
  fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;

  while (fluxoBrutoDeBitsPontoB.lenght != fluxoBrutoDeBitsPontoA) {
    if ((rand() % 100) == ...) // fazer a probabilidade do erro
      fluxoBrutoBitsPontoB += fluxoBrutoBitsPontoA; // BITS!!!
    else // ERRO! INVERTER (usa condicao ternaria)
        fluxoBrutoBitsPontoB==0) ?
        fluxoBrutoBitsPontoA=fluxoBrutoBitsPontoB++ :
        fluxoBrutoBitsPontoA=fluxoBrutoBitsPontoB--;
  }
}

///////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraControleDeFluxo        //
/////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraControleDeFluxo(int quadro[]) {
  // algum codigo aqui
}

//////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraControleDeErro        //
////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraControleDeErro(int quadro[]) {
  int tipoDeControleDeErro = 0; // alterar de acordo com o teste

  switch (tipoDeControleDeErro) {
  case 0: // bit de paridade par
    // codigo
    break;
  case 1: // bit de paridade impar
    // codigo
    break;
  case 2: // CRC
          // codigo
  case 3: // codigo de hamming
    // codigo
    break;
  }
}

//////////////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadePar //
////////////////////////////////////////////////////////////////////////////////
int CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadePar(int quadro[],
                                                             int size) {
  // implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
  int bitParidade;

  // Como foi adicionado um bit ao quadro para que a paridade ficasse par, o
  resultado
      // dessa função deve ser sempre 0, caso contrário ocorreu algum erro na
      transmissão bitParidade =
          CamadaEnlaceDadosTransmissoraControleDeErroBitDeParidadePar(quadro,
                                                                      size);

  // Retorna 1 se sucesso e 0 em caso de erro de transmissão
  return !bitParidade;
}

////////////////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadeImpar //
//////////////////////////////////////////////////////////////////////////////////
int CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadeImpar(int quadro[],
                                                               int size) {
  // implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
  int bitParidade;

  // Como foi adicionado um bit ao quadro para que a paridade ficasse ímpar, o
  resultado
      // dessa função deve ser sempre 0, caso contrário ocorreu algum erro na
      transmissão bitParidade =
          CamadaEnlaceDadosTransmissoraControleDeErroBitDeParidadeImpar(quadro,
                                                                        size);

  // Retorna 1 se sucesso e 0 em caso de erro de transmissão
  return !bitParidade;
}

/////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraControleDeErroCRC        //
///////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraControleDeErroCRC(int quadro[]) {
  // implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
  // usar polinomio CRC-32(IEEE 802)
}

/////////////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming        //
///////////////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming(int quadro[x]) {
  std::vector<int> avec;
  for (auto i = 0; i < x; i++) {
    avec.push_back(quadro[i]);
    auto m3 = 0, m5 = 0, m6 = 0, m7 = 0, m9 = 0, m10 = 0, m11 = 0, m12 = 0;
    auto soma = 0;
    for (auto i = 0; i < 8; i += 8) {
      m3 = (avec[i + 0] + avec[i + 1]) == avec[i + 2] ? 0 : 1;
      m5 = (avec[i + 3] + avec[i + 0]) == avec[i + 4] ? 0 : 1;
      m6 = (avec[i + 3] + avec[i + 1]) == avec[i + 5] ? 0 : 1;
      m7 = (avec[i + 3] + avec[i + 1] + avec[i + 0]) == avec[i + 6] ? 0 : 1;
      m9 = (avec[i + 7] + avec[i + 0]) == avec[i + 8] ? 0 : 1;
      m10 = (avec[i + 7] + avec[i + 1]) == avec[i + 9] ? 0 : 1;
      m11 = (avec[i + 7] + avec[i + 1] + avec[i + 0]) == avec[i + 10] ? 0 : 1;
      m12 = (avec[i + 7] + avec[i + 3]) == avec[i + 11] ? 0 : 1;
      soma = m3 + m5 + m7 + m9 + m10 + m11 + m12;

      if (soma != 8) {
        throw std::runtime_error(
            "a verificação do código de hamming detectou erro na transmissão");
      }
    }
  }

  std::cout << "não houve erro com o código de hamming";
}
*/