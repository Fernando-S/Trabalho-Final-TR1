#ifndef CAMADA_ENLACE_H
#define CAMADA_ENLACE_H


void CamadaEnlaceDadosTransmissora (int quadro[],int size);

void CamadaEnlaceDadosTransmissoraEnquadramento (int quadro[], int size);

void CamadaDeEnlaceTransmissoraEnquadramentoContagemDeCaracteres (int quadro[], int size);

void CamadaEnlaceDadosReceptoraEnquadramento (int quadro [], int size);

void CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres (int quadro [], int size);

void CamadaEnlaceDadosTransmissoraControleDeErro (int quadro [], int size);

void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(int quadro[], int size);

void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(int quadro[], int size);

void MeioDeComunicacao(int fluxoBrutoDeBits[], int size, int tipoDeControleDeErro);

void CamadaEnlaceDadosReceptoraControleDeErro(int quadro[], int size, int tipoDeControleDeErro);

void CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadePar(int quadro[], int size);

int CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadeImpar(int quadro[],int size);

void CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming (int quadro[], int size);

void CamadaEnlaceDadosReceptora (int quadro [], int size, int tipoDeControleDeErro);

void CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBytes (int quadro [], int size);

void CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBits (int quadro [], int size);

void CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes (int quadro [], int size);

void CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBits (int quadro[], int size);

void CamadaEnlaceDadosTransmissoraControleDeErro (int quadro[], int size);

/* Calcula o bit de paridade do quadro para que sua paridade seja par.
 * Args:
 *    quadro, vetor de bits.
 *    size_quadro, número de elementos do quadro.
 * Return:
 *    bitParidade, valor 0 ou 1 que deve ser concatenado ao quadro para que sua
 *          paridade seja par.
*/
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar (int quadro[], int size_quadro);

/* Calcula o bit de paridade do quadro para que sua paridade seja ímpar.
 * Args:
 *    quadro, vetor de bits.
 *    size_quadro, número de elementos do quadro.
 * Return:
 *    bitParidade, valor 0 ou 1 que deve ser concatenado ao quadro para que sua
 *          paridade seja ímpar.
*/
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar (int quadro[], int size_quadro);


void CamadaEnlaceDadosTransmissoraControleDeErroCRC (int quadro[], int size);


void CamadaEnlaceDadosReceptoraControleDeErroCRC (int quadro_extentido[], int size);

void CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming (int quadro[], int size);

#endif  // CAMADA_ENLACE_H
