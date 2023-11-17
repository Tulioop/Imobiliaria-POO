#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "imovel.h"
#include "apartamento.h"
#include "casa.h"
#include "chacara.h"
#include "functions.h"

using namespace std;

int main(){

    vector<Imovel> listaDeImoveis; 

    // EXEMPLO SE ALGUM PROPRIETÁRIO TEM IMÓVEL
    bool possuiImovel = possuiImovelDoProprietario(listaDeImoveis, nomeProcurado);
    string nomeProcurado = "Maria";
    if (possuiImovel){
        cout << "O proprietario " << nomeProcurado << " possui imovel." << endl;
    }else{
        cout << "O proprietario " << nomeProcurado << " nao possui imovel." << endl;
    }

    // EXEMPLO DE LISTA TODOS IMÓVEIS COM VALORES X OU MENOR
    float valorMaximo = 200000.0;
    vector<Imovel> imoveisFiltrados = filtrarImoveisPorValor(listaDeImoveis, valorMaximo);
    cout << "Imoveis com valor igual ou abaixo de R$" << valorMaximo << ":" << endl;
    for (const Imovel& imovel : imoveisFiltrados) {
        cout << imovel << endl;
    }

    // EXEMPLO LISTA TODOS IMÓVEIS COM QTDE DE QUARTO X OU MAIS
    int numQuartos = 3;
    vector<Imovel> imoveisFiltrados = filtrarImoveisPorQuartos(listaDeImoveis, numQuartos);
    cout << "Imoveis com " << numQuartos << " quartos ou mais:" << endl;
    for (const Imovel& imovel : imoveisFiltrados) {
        cout << imovel << std::endl;
    }

    // EXEMPLO LISTA TIPO DE IMOVEL E ORDENA PELO VALOR E IMPRIME CARACTERISTICAS
    TipoImovel tipoProcurado = TipoImovel::CASA;

    vector<Imovel> imoveisFiltrados = filtrarImoveisPorTipoEValor(listaDeImoveis, tipoProcurado);
    cout << "Imoveis do tipo ";

    switch (tipoProcurado) {
        case TipoImovel::CASA:
            cout << "Casa:" << endl;;
            break;
        case TipoImovel::APARTAMENTO:
            cout << "Apartamento:" << endl;;
            break;
        case TipoImovel::CHACARA:
            cout << "Chacara:" << endl;;
            break;
    }

    for (const Imovel& imovel : imoveisFiltrados) {
        cout << printInfo(imovel) << endl;
    }

    // EXEMPLO LISTA TODOS IMOVEIS DE UMA CIDADE E ORDENA DESCRESCENTE DE VALOR
    string cidadeProcurada = "São Paulo";
    vector<Imovel> imoveisFiltrados = filtrarImoveisPorCidade(listaDeImoveis, cidadeProcurada);

    cout << "Imoveis em " << cidadeProcurada << " ordenados por valor (decrescente):" << endl;
    for (const Imovel& imovel : imoveisFiltrados) {
        cout << imovel << endl;
    }

    // EXEMPLO RETORNA ITERADOR DADO UM PROPRIETARIO E PRINTA DADOS DO IMOVEL
    string nomeProcurado = "João";
    auto iteradoresPorTipo = encontrarImoveisPorProprietario(listaDeImoveis, nomeProcurado);
    cout << "Imoveis do proprietario " << nomeProcurado << ":" << endl;

    for (const auto& pair : iteradoresPorTipo) {
        cout << "Tipo de imovel: ";
        switch (pair.first) {
            case TipoImovel::CASA:
                printInfo(Imovel& imovel);
                break;
            case TipoImovel::APARTAMENTO:
                printInfo(Imovel& imovel);;
                break;
            case TipoImovel::CHACARA:
                printInfo(Imovel& imovel);
                break;
        }
        cout << *(pair.second) << endl;
    }



    return 0;
}