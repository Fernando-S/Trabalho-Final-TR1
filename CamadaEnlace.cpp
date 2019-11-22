#include "CamadaEnlace.h"
#include "CamadaFisica.h"
#include "Simulador.h"
#include "iostream"
#include "vector"
#include <time.h>
#include <stdlib.h>

// Verifica de MSG[IDX] até MSG[IDX+7] se é idêntico a FLAGorESC[0] até FLAGorESC[7]
#define isFlagOrEscape(MSG,IDX,FLAGorESC) ((MSG[IDX]==FLAGorESC[0] && MSG[IDX+1]==FLAGorESC[1] && \
    MSG[IDX+2]==FLAGorESC[2] && MSG[IDX+3]==FLAGorESC[3] && MSG[IDX+4]==FLAGorESC[4] && \
    MSG[IDX+5]==FLAGorESC[5] && MSG[IDX+6]==FLAGorESC[6] && MSG[IDX+7]==FLAGorESC[7]))

/* Atribui-se a MSG[IDX_MSG] até MSG[IDX_MSG+7] os valores de BITS[IDX_BITS] até BITS[IDX_BITS+7].
 * Assume-se que BITS tem 8 elementos.
 */
#define add8Bits(MSG, IDX_MSG, BITS, IDX_BITS) MSG[IDX_MSG]=BITS[IDX_BITS];MSG[IDX_MSG+1]=BITS[IDX_BITS+1];\
    MSG[IDX_MSG+2]=BITS[IDX_BITS+2];MSG[IDX_MSG+3]=BITS[IDX_BITS+3];MSG[IDX_MSG+4]=BITS[IDX_BITS+4];\
    MSG[IDX_MSG+5]=BITS[IDX_BITS+5];MSG[IDX_MSG+6]=BITS[IDX_BITS+6];MSG[IDX_MSG+7]=BITS[IDX_BITS+7]

const int FLAG_BYTES[] = {0,1,0,0,0,0,0,0}; //< (char) 64 == '@'; essa é a flag
const int ESCAPE_BYTES[] = {0,0,1,1,1,1,1,1}; // (char) 63 == '?'; esse é o escape

extern int TIPO_ENQUADRAMENTO; //< Declarado em Simulador.h

using namespace std;


///////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissora        //
/////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissora (int quadro [], int size) {

    

   CamadaEnlaceDadosTransmissoraEnquadramento(quadro, size);
//    CamadaEnlaceDadosTransmissoraControleDeErro(quadro,size);
//    CamadaEnlaceDadosTransmissoraControleDeFluxo(quadro,size);
    //chama proxima camada
//    CamadaFisicaTransmissora(quadro,size);
}
/*

///////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceTransmissoraEnquadramento        //
/////////////////////////////////////////////////////////////
*/
void CamadaEnlaceDadosTransmissoraEnquadramento (int quadro [],int size) {

    do {
        cout << "Tipo de enquadramento (0: contagem de caracteres, 1: inserção de bytes): ";
        cin >> TIPO_ENQUADRAMENTO;
    } while(TIPO_ENQUADRAMENTO < 0 || TIPO_ENQUADRAMENTO > 3);

    switch (TIPO_ENQUADRAMENTO) {
        case 0 : //contagem de caracteres
            CamadaDeEnlaceTransmissoraEnquadramentoContagemDeCaracteres(quadro,size);
            break;
        case 1 : //insercao de bytes quadroEnquadrado =
            CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBytes(quadro,size);
            break;
        case 2 :
//insercao de bits quadroEnquadrado =
//CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBits(quadro,size);
        break;
        case 3 :
//violacao da camada fisica quadroEnquadrado =
//CamadaDeEnlaceTransmissoraEnquadramentoViolacaoCamadaFisica(quadro,size);
        break;
    }
}


///////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraContagemDeCaracteres        //
/////////////////////////////////////////////////////////////////////////
void CamadaDeEnlaceTransmissoraEnquadramentoContagemDeCaracteres (int quadro [], int size) {
    //implementacao do algoritmo
    int i, qtd, newsize;
    qtd = size/7;
//    cout << qtd;
    int quadro_invertido[7];
    newsize = size + 7;
    int newquadro[newsize];
    for(i = newsize-1; i>=0; i--){
        newquadro[i] = quadro[i-7];
    }
    cout << endl;
    i = 0;
    while(qtd > 0){
        quadro_invertido[i] = qtd%2;
        qtd /= 2;
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




    cout << endl;
    int j = 0;
    i = 6;
    while(j<7){
      newquadro[j] = quadro_invertido[i];
      j++;
      i--;
    }
    cout<<"\nEnquadramento por contagem de caracteres: " << endl;
    for(i=0; i<newsize; i++){
      cout << newquadro[i];
    }
    cout << "\n" << endl;
    CamadaEnlaceDadosTransmissoraControleDeErro(newquadro, newsize);

}

//////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraInsercaoDeBytes        //
////////////////////////////////////////////////////////////////////
void CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBytes (int quadro [], int size) {
    int qtEscapesAndFlags = 0, i;

    // Percorremos cada bit procurando pelo padrão da flag
    // Obs.: isFlagOrEscape não é uma função, é um #define
    for(i = 0; i < size -7; i++) {
        if(isFlagOrEscape(quadro, i, FLAG_BYTES) || isFlagOrEscape(quadro, i, ESCAPE_BYTES)) {
            qtEscapesAndFlags++;
            i += 7;
        }
    }

    // O novo quadro terá tamanho size, mais 8 vezes o número de flags e
    // de escapes, mais 16, pois serão adicionadas flags no início e no fim
    int newsize = size + 8*qtEscapesAndFlags + 16;
    int newquadro[newsize];

    add8Bits(newquadro, 0, FLAG_BYTES, 0);
    add8Bits(newquadro, newsize -8, FLAG_BYTES, 0);

    for(int newquadroIdx = 8, i = 0; i < size; newquadroIdx++, i++) {
        // Se encontramos um símbolo de escape ou de flag na mensagem,
        // precisamos ignorar esses 8 bits adicionando um símbolo de 
        // escape antes
        if(size - i >= 8 && (isFlagOrEscape(quadro, i, FLAG_BYTES) || \
                isFlagOrEscape(quadro, i, ESCAPE_BYTES))) {
            add8Bits(newquadro, newquadroIdx, ESCAPE_BYTES, 0);
            newquadroIdx += 8;
            add8Bits(newquadro, newquadroIdx, quadro, i);
            newquadroIdx += 7;
            i += 7;
        }
        else
            newquadro[newquadroIdx] = quadro[i];
    }

    cout << "\nEnquadramento por inserção de bytes: " << endl;
    cout << "FLAG:   ";
    for(i = 0; i < 8; i++)
        cout << FLAG_BYTES[i];
    cout << "\nESCAPE: ";
    for(i = 0; i < 8; i++)
        cout << ESCAPE_BYTES[i];
    cout << "\nQuadro: ";
    for(i=0; i<newsize; i++)
      cout << newquadro[i];
    cout << "\n" << endl;

    CamadaEnlaceDadosTransmissoraControleDeErro(newquadro, newsize);
}


/*
/////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraInsercaoDeBits        //
///////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBits (int quadro [], int size) {
    //implementacao do algoritmo
}


////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptora        //
//////////////////////////////////////////////////
*/
void CamadaEnlaceDadosReceptora (int quadro [], int size, int tipoDeControleDeErro) {
    CamadaEnlaceDadosReceptoraControleDeErro(quadro,size, tipoDeControleDeErro);

}


/////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraEnquadramento        //
///////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraEnquadramento (int quadro [], int size) {

    switch (TIPO_ENQUADRAMENTO) {
        case 0 : //contagem de caracteres
            CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(quadro,size);
            break;
        case 1 : //insercao de bytes quadroDesenquadrado =
            CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(quadro, size);
            break;
        case 2 : //insercao de bits quadroDesenquadrado =
//CamadaDeEnlaceReceptoraEnquadramentoInsercaoDeBits(quadro, size); //sem break??
            break;
    }
}
/*

////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraContagemDeCaracteres        //
//////////////////////////////////////////////////////////////////////
*/
void CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres (int quadro [], int size)
{
    //implementacao do algoritmo para DESENQUADRAR
    int i;
    int newquadro[size-7];
    cout << "\nQuadro após o desenquadramento: ";
    for(i = 0; i<size-7; i++){
      newquadro[i] = quadro[i+7];
      cout << newquadro[i];
    }
    cout<< "\n";

      CamadaDeAplicacaoReceptora(newquadro, size-7);
}


///////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraInsercaoDeBytes        //
/////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes (int quadro [], int size) {
    int i;
    //Utilizado para contar quandos bytes da msg original foram escapados
    int qtEscapedBytes = 0;

    // Percorremos cada bit procurando pelo padrão de escape, se houver,
    // há, na mensagem, um padrão de bits correspondente ao de escape ou
    // de flag, totalizando 8 bits de mensagem.
    // Obs.: isFlagOrEscape não é uma função, é um #define
    for(i = 8; i < size -7; i++) {
        // Se encontrar um escape, pula o escape e os próximos 8 bits, totalizando
        // um salto de 16 bits
        if(isFlagOrEscape(quadro, i, ESCAPE_BYTES)) {
            qtEscapedBytes++;
            i += 15; //< Add 15 porque o for adicionara +1 depois
        }
    }

    // O novo quadro terá tamanho size, menos 8 vezes o número de escapeds 
    // encontrados, menos 16, pois serão removidas as flags de início e fim
    int newsize = size - 8*qtEscapedBytes - 16;
    int newquadro[newsize];

    //add8Bits(newquadro, 0, FLAG_BYTES, 0); <<<<<<<<<<<< IGNORAR OS 8 PRIMEIROS E ULTIMOS BITS
    //add8Bits(newquadro, newsize -8, FLAG_BYTES, 0);

    // Começamos a iteração pulando a flag e ignoramos a última. A última flag
    // será automaticamente ignorada quando todo o newquadro for preenchido.
    for(int i = 8, newquadroIdx = 0; newquadroIdx < newsize; newquadroIdx++, i++) {
        // Se encontramos um símbolo de escape, pulamos ele e adicionamos os 8
        // próximos bits ao newquadro
        if(newsize - newquadroIdx >= 8 && isFlagOrEscape(quadro, i, ESCAPE_BYTES)) {
            i += 8; //< Pulamos o escape
            // Sabemos que há 8 bits a seguir, pois o escape estava inserido
            // para escapar um símbolo especial (FLAG_BITS ou ESCAPE_BITS) 
            // que fazia parte da mensagem e que tem tamanho de 1 byte
            add8Bits(newquadro, newquadroIdx, quadro, i);
            newquadroIdx += 7;
            i += 7;
        }
        else
            newquadro[newquadroIdx] = quadro[i];
    }

    cout << "\nDesenquadramento por inserção de bytes: " << endl;
    cout << "FLAG:   ";
    for(i = 0; i < 8; i++)
        cout << FLAG_BYTES[i];
    cout << "\nESCAPE: ";
    for(i = 0; i < 8; i++)
        cout << ESCAPE_BYTES[i];
    cout << "\nQuadro: ";
    for(i=0; i<newsize; i++)
      cout << newquadro[i];
    cout << "\n" << endl;

    CamadaDeAplicacaoReceptora(newquadro, newsize);
}


/*
//////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraInsercaoDeBits        //
////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBits (int quadro[], int size) {
    //implementacao do algoritmo para DESENQUADRAR
}


//////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraControleDeFluxo        //
////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraControleDeFluxo (int quadro [], int size) {
    //algum codigo aqui
}


/////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraControleDeErro        //
///////////////////////////////////////////////////////////////////
*/
void CamadaEnlaceDadosTransmissoraControleDeErro (int quadro [], int size) {
    int tipoDeControleDeErro; //alterar de acordo com o teste
    cout << "Tipo de controle de erro (0: bit de paridade par, 1: bit de paridade impar): ";
    cin >> tipoDeControleDeErro;
    switch (tipoDeControleDeErro) {
        case 0 : //bit de paridade par
            CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(quadro, size);
            break;
        case 1 : //bit de paridade impar
            CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(quadro, size);
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
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(int quadro[], int size) {
    // Retorna o valor do bit de paridade que deve ser concatenado ao quadro
    int bitParidade = 0;
    int newquadro[size+1];
    int i=0;
    for(int i = 0; i < size; i++) {
        bitParidade ^= quadro[i];
    }
    for(i=0; i<size; i++){
      newquadro[i] = quadro[i];
    }
    newquadro[size] = bitParidade;

    //chamar próxima funcao
    CamadaFisicaTransmissora(newquadro, size+1, 0);
//    MeioDeComunicacao(newquadro, size+1, 0);//retirar depois, apenas para teste!!!!!
}


/////////////////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraControledeErroBitParidadeImpar //
///////////////////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(int quadro[], int size) {
    // Retorna o valor do bit de paridade que deve ser concatenado ao quadro
    int bitParidade = 0;
    int newquadro[size+1];
    int i=0;
    for(int i = 0; i < size; i++) {
        bitParidade ^= quadro[i];
    }
    for(i=0; i<size; i++){
      newquadro[i] = quadro[i];
    }
    newquadro[size] = bitParidade ^= 1;

  //chamar proxima funcao
CamadaFisicaTransmissora(newquadro, size+1, 0);

}
/*

////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraControledeErroCRC        //
//////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraControleDeErroCRC (int quadro [], int size) {
    //implementacao do algoritmo
    //usar polinomio CRC-32(IEEE 802)
}


////////////////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosTransmissoraControleDeErroCodigoDehamming //
//////////////////////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming(int quadro [], int size) {
  std::vector<int> avec;
  for (auto i = 0; i < size; i++) {
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
*/

  // OBS: trabalhar com BITS e nao com BYTES!!!
  /*
  int erro, porcentagemDeErros;
  int fluxoBrutoDeBitsPontoA[size], fluxoBrutoDeBitsPontoB[size];

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
  */

/*
///////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraControleDeFluxo        //
/////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraControleDeFluxo(int quadro[], int size) {
  // algum codigo aqui
}
*/
//////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraControleDeErro        //
////////////////////////////////////////////////////////////////
void CamadaEnlaceDadosReceptoraControleDeErro(int quadro[], int size, int tipoDeControleDeErro) {

  switch (tipoDeControleDeErro) {
  case 0: // bit de paridade par
    CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadePar(quadro, size);
    break;
  case 1: // bit de paridade impar
    CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadeImpar(quadro, size);
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
void CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadePar(int quadro[], int size) {
  // implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
  int bitTeste;
  int newquadro[size-1];

  cout << "\nVerificando paridade par do quadro recebido..." << endl;

  int i=0, teste=0;
  for(int i = 0; i < 6; i++) {
      teste ^= quadro[i];
  }
  if(teste == 1){                           //se teste = 0, o quadro foi passado corretamente
    cout << "\nQuadro correto." << endl;
  }
  if(teste == 0){                           //se teste = 1, houve erro na transmissao do quadro
    cout << "\nHouve erro na trasmissão do quadro.";
  }

  for(i=0; i<size-1; i++){
    newquadro[i] = quadro[i];
  }

  CamadaEnlaceDadosReceptoraEnquadramento(newquadro, size-1);

}

////////////////////////////////////////////////////////////////////////////////////
//      Metodo CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadeImpar //
//////////////////////////////////////////////////////////////////////////////////
int CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadeImpar(int quadro[],int size) {
  int bitTeste;
  int newquadro[size-1];

  cout << "\nVerificando paridade par do quadro recebido..." << endl;

  int i=0, teste=0;
  for(int i = 0; i < 6; i++) {
    teste ^= quadro[i];
    cout << teste;
  }
  if(teste == 1){                           //se teste = 0, o quadro foi passado corretamente
    cout << "\nQuadro correto." << endl;
  }
  if(teste == 0){                           //se teste = 1, houve erro na transmissao do quadro
    cout << "\nHouve erro na trasmissão do quadro.";
  }

  for(i=0; i<size-1; i++){
    newquadro[i] = quadro[i];
  }
  //chama prox funcao
  CamadaEnlaceDadosReceptoraEnquadramento(newquadro, size-1);

}
/*
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
