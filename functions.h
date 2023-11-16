#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "casa.h"
#include "apartamento.h"
#include "chacara.h"

void printInfo(const Imovel& imovel);

bool possuiImovelDoProprietario(const std::vector<Imovel>& imoveis, const std::string& nomeProprietario);

vector<Imovel> filtrarImoveisPorValor(const std::vector<Imovel>& imoveis, float valorMaximo);

vector<Imovel> filtrarImoveisPorQuartos(const std::vector<Imovel>& imoveis, int numQuartos);

vector<Imovel> filtrarImoveisPorTipoEValor(const vector<Imovel>& imoveis, TipoImovel tipo)
#endif 