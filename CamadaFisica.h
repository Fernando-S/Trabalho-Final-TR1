#ifndef CAMADA_FISICA_H
#define CAMADA_FISICA_h

#include <string>
#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>


using namespace std;

void CamadaFisicaTransmissora (int quadro[], int size);

void CamadaFisicaTransmissoraCodificacaoBinaria (int quadro [], int size);


/* Realiza a codificação manchester de um quadro de dados, segundo a convenção
 * de G. E. Thomas.
 *
 * Args:
 *    quadro, vetor de valores binários.
 *    quadro_size, quantidade de elementos do quadro.
 *    manchester, deve ser um vetor de tamanho quadro_size*2 (já alocado). O
 *        quadro com a codificação Manchester estará nesses endereços após a
 *        execução desta função.
 */
void CamadaFisicaTransmissoraCodificacaoManchester (int quadro[], int quadro_size);

void CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int quadro[], int size);

void MeioDeComunicacao (int fluxoBrutoDeBits[], int size, int tipoDeDecodificacao);

void CamadaFisicaReceptora (int quadro[], int size, int tipoDeDecodificacao);

void CamadaFisicaReceptoraDecodificacaoBinaria (int quadro[], int size);

void CamadaFisicaReceptoraDecodificacaoManchester (int* manchester, int size);

void CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(int quadro[], int size);

void CamadaDeAplicacaoReceptora (int quadro[], int size);

void AplicacaoReceptora (string mensagem);

// Realiza a operação a XNOR b.
int bitXnor(int a, int b);

string binarioparastring(int* vetor, int size);

#endif // CAMADA_FISICA_H
