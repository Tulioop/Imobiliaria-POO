#include "functions.h"
#include <iostream>
#include <vector>
#include <fstream>

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
bool possuiImovelDoProprietario(const vector<Imovel>& imoveis, const string& nomeProprietario) {
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
vector<Imovel> filtrarImoveisPorTipoEValor(const stdvector<Imovel>& imoveis, TipoImovel tipo) {
    stdvector<Imovel> imoveisDoTipo;

    for (const Imovel& imovel : imoveis) {
        if (imovel.getTipo() == tipo) {
            imoveisDoTipo.push_back(imovel);
        }
    }
    sort(imoveisDoTipo.begin(), imoveisDoTipo.end(),
              [](const Imovel& a, const Imovel& b) { return a.getValor() < b.getValor(); });

    return imoveisDoTipo;
}

// LISTA TODOS IMOVEIS DE UMA CIDADE E ORDENA DESCRESCENTE DE VALOR
vector<Imovel> filtrarImoveisPorCidade(const vector<Imovel>& imoveis, const string& cidade) {
    vector<Imovel> imoveisNaCidade;
    for (const Imovel& imovel : imoveis) {
        if (imovel.getCidade() == cidade) {
            imoveisNaCidade.push_back(imovel);
        }
    }
    
    sort(imoveisNaCidade.begin(), imoveisNaCidade.end(),
              [](const Imovel& a, const Imovel& b) { return a.getValor() > b.getValor(); });

    return imoveisNaCidade;
}

// RETORNA ITERADOR DADO UM PROPRIETARIO E PRINTA DADOS DO IMOVEL
unordered_map<TipoImovel, stdvector<Imovel>::const_iterator> encontrarImoveisPorProprietario(const vector<Imovel>& imoveis, const string& nomeProprietario) {

    unordered_map<TipoImovel, std::vector<Imovel>::const_iterator> iteradoresPorTipo;

    for (auto it = imoveis.cbegin(); it != imoveis.cend(); ++it) {
        if (it->getProprietario() == nomeProprietario) {
            auto tipoImovel = it->getTipo();
            if (iteradoresPorTipo.find(tipoImovel) == iteradoresPorTipo.end()) {
                iteradoresPorTipo[tipoImovel] = it;
            }
        }
    }
    return iteradoresPorTipo;
}

// LISTA COLEÇÃO IMOVEIS PARA PODER SALVAR EM ARQUIVO TXT
void mostrarOuSalvarImoveis(const vector<Imovel*>& imoveis, TipoSaida tipoSaida) {
    if (tipoSaida == TipoSaida::TERMINAL) {
        for (const auto& imovel : imoveis) {
            imovel->mostrarDados(cout);
        }
    } else if (tipoSaida == TipoSaida::ARQUIVO) {
        ofstream arquivo("saida.txt");
        if (arquivo.is_open()) {
            for (const auto& imovel : imoveis) {
                imovel->salvarDados(arquivo);
            }
            arquivo.close();
        } else {
            cerr << "Não foi possível abrir o arquivo." << endl;
        }
    }
}

