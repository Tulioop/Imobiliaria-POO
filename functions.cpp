#include "functions.h"
#include <iostream>
#include <vector>

using namespace std;

// IMPRESSÃO DE DADOS DE UM IMÓVEL
void printInfo(const Imovel& imovel) {
    cout << "Detalhes do Imovel:" << endl;
    cout << imovel << endl;
    cout << "---------------------------------------" << endl;

    const Casa* casa = dynamic_cast<const Casa*>(&imovel);
    if (casa != nullptr) {
        cout << "Tipo: Casa" << endl;
        cout << *casa << endl;
        cout << "---------------------------------------" << endl;
        return;
    }

    const Apartamento* apartamento = dynamic_cast<const Apartamento*>(&imovel);
    if (apartamento != nullptr) {
        cout << "Tipo: Apartamento" << endl;
        cout << *apartamento << endl;
        cout << "---------------------------------------" << endl;
        return;
    }

    const Chacara* chacara = dynamic_cast<const Chacara*>(&imovel);
    if (chacara != nullptr) {
        cout << "Tipo: Chacara" << endl;
        cout << *chacara << endl;
        cout << "---------------------------------------" << endl;
        return;
    }

    cout << "Tipo desconhecido" << endl;
    cout << "---------------------------------------" << endl;
}

// VERIFICA SE ALGUM PROPRIETÁRIO TEM IMÓVEL
bool possuiImovelDoProprietario(const std::vector<Imovel>& imoveis, const std::string& nomeProprietario) {
    for (const Imovel& imovel : imoveis) {
        if (imovel.getProprietario() == nomeProprietario) {
            return true;
        }
    }
    return false;
}

// LISTA TODOS IMÓVEIS COM VALORES X OU MENOR
vector<Imovel> filtrarImoveisPorValor(const vector<Imovel>& imoveis, float valorMaximo) {
    vector<Imovel> imoveisFiltrados;

    for (const Imovel& imovel : imoveis) {
        if (imovel.getValor() <= valorMaximo) {
            imoveisFiltrados.push_back(imovel);
        }
    }
    return imoveisFiltrados;
}

// LISTA TODOS IMÓVEIS COM QTDE DE QUARTO X OU MAIS
vector<Imovel> filtrarImoveisPorQuartos(const vector<Imovel>& imoveis, int numQuartos) {
    vector<Imovel> imoveisFiltrados;

    for (const Imovel& imovel : imoveis) {
        if (imovel.getQuartos() >= numQuartos) {
            imoveisFiltrados.push_back(imovel);
        }
    }
    return imoveisFiltrados;
}

// LISTA TIPO DE IMOVEL E ORDENA PELO VALOR E IMPRIME CARACTERISTICAS
vector<Imovel> filtrarImoveisPorTipoEValor(const vector<Imovel>& imoveis, TipoImovel tipo) {
    vector<Imovel> imoveisDoTipo;
    for (const Imovel& imovel : imoveis) {
        if (imovel.getTipo() == tipo) {
            imoveisDoTipo.push_back(imovel);
        }
    }
    sort(imoveisDoTipo.begin(), imoveisDoTipo.end(),
              [](const Imovel& a, const Imovel& b) { return a.getValor() < b.getValor(); });

    return imoveisDoTipo;
}