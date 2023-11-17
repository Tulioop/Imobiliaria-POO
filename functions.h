#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <unordered_map>
#include <iterator>
#include <algorithm>

#include "casa.h"
#include "apartamento.h"
#include "chacara.h"

void printInfo(const Imovel& imovel);

bool possuiImovelDoProprietario(const vector<Imovel>& imoveis, const string& nomeProprietario);

vector<Imovel> filtrarImoveisPorValor(const vector<Imovel>& imoveis, float valorMaximo);

vector<Imovel> filtrarImoveisPorQuartos(const vector<Imovel>& imoveis, int numQuartos);

vector<Imovel> filtrarImoveisPorTipoEValor(const vector<Imovel>& imoveis, TipoImovel tipo);

vector<Imovel> filtrarImoveisPorCidade(const vector<Imovel>& imoveis, const string& cidade);

unordered_map<TipoImovel, vector<Imovel>::const_iterator> encontrarImoveisPorProprietario(const vector<Imovel>& imoveis, const string& nomeProprietario);

enum class TipoSaida {
    TERMINAL,
    ARQUIVO
};

void mostrarOuSalvarImoveis(const std::vector<Imovel*>& imoveis, TipoSaida tipoSaida);


#endif 