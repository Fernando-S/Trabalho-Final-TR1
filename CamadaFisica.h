#ifndef CAMADA_FISICA_H
#define CAMADA_FISICA_h

void CamadaFisicaTransmissora (int quadro[], int size);

int* CamadaFisicaTransmissoraCodificacaoBinaria (int quadro [], int size);

int* CamadaFisicaTransmissoraCodificacaoManchester (int quadro [], int size);

int* CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int quadro [], int size);

void MeioDeComunicacao (int fluxoBrutoDeBits [], int size);

void CamadaFisicaReceptora (int quadro[], int size);
/*
int[] CamadaFisicaReceptoraCodificacaoBinaria (int quadro []);

int[] CamadaFisicaReceptoraCodificacaoManchester (int quadro []);

int[] CamadaFisicaReceptoraCodificacaoManchesterDiferencial (int quadro[]);

void CamadaDeAplicacaoReceptora (int quadro []);

void AplicacaoReceptora (string mensagem);
*/
#endif // CAMADA_FISICA_H