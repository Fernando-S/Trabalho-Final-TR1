#ifndef CAMADA_ENLACE_H
#define CAMADA_ENLACE_H

/*
void CamadaEnlaceDadosTransmissora (int quadro[]);

void CamadaEnlaceDadosTransmissoraEnquadramento (int quadro[]);

void CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres (int quadro[]);

void CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes (int quadro[]);

void CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBits (int quadro[]);

void CamadaEnlaceDadosTransmissoraEnquadramentoViolacaoDaCamadaFisica (int quadro[]);

void CamadaEnlaceDadosReceptora (int quadro[]);

void CamadaEnlaceDadosReceptoraEnquadramento (int quadro[]);

void CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres (int quadro[]);

void CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes (int quadro[]);

void CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBits (int quadro[]);

void CamadaEnlaceDadosReceptoraEnquadramentoViolacaoDaCamadaFisica(int quadro[]);

void CamadaEnlaceDadosTransmissoraControleDeFluxo (int quadro[]);

void CamadaEnlaceDadosTransmissoraControleDeErro (int quadro[]);
*/

/* Calcula o bit de paridade do quadro para que sua paridade seja par.
 * Args:
 *    quadro, vetor de bits.
 *    size_quadro, número de elementos do quadro.
 * Return:
 *    bitParidade, valor 0 ou 1 que deve ser concatenado ao quadro para que sua
 *          paridade seja par.

int CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar (int quadro[], int size_quadro);

/* Calcula o bit de paridade do quadro para que sua paridade seja ímpar.
 * Args:
 *    quadro, vetor de bits.
 *    size_quadro, número de elementos do quadro.
 * Return:
 *    bitParidade, valor 0 ou 1 que deve ser concatenado ao quadro para que sua
 *          paridade seja ímpar.

int CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar (int quadro[], int size_quadro);


void CamadaEnlaceDadosTransmissoraControleDeErroCRC (int quadro[]);

void CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming (int quadro[]);

void CamadaEnlaceDadosReceptoraControleDeFluxo ( int quadro[]);

void CamadaEnlaceDadosReceptoraControleDeErro (int quadro[]);
*/

/* Calcula o bit de paridade do quadro recebido, retorna 1 no caso em que a 
 * transmissão foi bem sucedida, 0 caso contrário.
 * Args:
 *    quadro, vetor de bits.
 *    size_quadro, número de elementos do quadro.
 * Return:
 *    sucesso, valor 1 ou 0 indicando o sucesso da operação ou não, respectivamente.

int CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadePar (int quadro[], int size);

/* Calcula o bit de paridade do quadro recebido, retorna 1 no caso em que a 
 * transmissão foi bem sucedida, 0 caso contrário.
 * Args:
 *    quadro, vetor de bits.
 *    size_quadro, número de elementos do quadro.
 * Return:
 *    sucesso, valor 1 ou 0 indicando o sucesso da operação ou não, respectivamente.

int CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadeImpar (int quadro[], int size);

/*
void CamadaEnlaceDadosReceptoraControleDeErroCRC (int quadro[]);

void CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming (int quadro[]);
 */

#endif  // CAMADA_ENLACE_H
