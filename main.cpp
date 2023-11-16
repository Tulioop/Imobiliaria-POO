#include <iostream>
#include <string>
#include <vector>
#include "imovel.h"
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

    

    return 0;
}