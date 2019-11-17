#ifndef CAMADA_FISICA_H
#define CAMADA_FISICA_h

/*************************************************************
* NAO ESQUECER DOS COMENTARIOS!
*********************************************************** */
void main (void);

void AplicacaoTransmissora (void);

void CamadaDeAplicacaoTransmissora (string mensagem);

void CamadaFisicaTransmissora (int quadro[]);

int[] CamadaFisicaTransmissoraCodificacaoBinaria (int quadro []);

int[] CamadaFisicaTransmissoraCodificacaoManchester (int quadro []);

int[] CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int quadro []);

void MeioDeComunicacao (int fluxoBrutoDeBits []);

void CamadaFisicaReceptora (int quadro[]);

int[] CamadaFisicaReceptoraCodificacaoBinaria (int quadro []);

int[] CamadaFisicaReceptoraCodificacaoManchester (int quadro []);

int[] CamadaFisicaReceptoraCodificacaoManchesterDiferencial (int quadro[]);

void CamadaDeAplicacaoReceptora (int quadro []);

void AplicacaoReceptora (string mensagem);

#endif