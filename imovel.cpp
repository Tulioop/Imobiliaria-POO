#include <iostream>
#include <string>

using namespace std;

class Imovel {
private:
    int id;
    float valor;
    string proprietario;
    string rua;
    string bairro;
    string cidade;
    int numero;
    int quartos;
    int banheiros;

public:
    // Métodos set
    void setId(int newId) {
        id = newId;
    }

    void setValor(float newValue) {
        valor = newValue;
    }

    void setProprietario(string newProprietario) {
        proprietario = newProprietario;
    }

    void setRua(string newRua) {
        rua = newRua;
    }

    void setBairro(string newBairro) {
        bairro = newBairro;
    }

    void setCidade(string newCidade) {
        cidade = newCidade;
    }

    void setNumero(int newNumero) {
        numero = newNumero;
    }

    void setQuartos(int newQuartos) {
        quartos = newQuartos;
    }

    void setBanheiros(int newBanheiros) {
        banheiros = newBanheiros;
    }

    // Métodos get
    int getId() const {
        return id;
    }

    float getValor() const {
        return valor;
    }

    string getProprietario() const {
        return proprietario;
    }

    string getRua() const {
        return rua;
    }

    string getBairro() const {
        return bairro;
    }

    string getCidade() const {
        return cidade;
    }

    int getNumero() const {
        return numero;
    }

    int getQuartos() const {
        return quartos;
    }

    int getBanheiros() const {
        return banheiros;
    }
    
    friend ostream& operator<<(ostream& out, const Imovel& imovel) {
        out << "ID: " << imovel.id << endl;
        out << "Valor: " << imovel.valor << endl;
        out << "Proprietario: " << imovel.proprietario << endl;
        out << "Endereco: " << imovel.rua << ", " << imovel.bairro << ", " << imovel.cidade << endl;
        out << "Numero: " << imovel.numero << endl;
        out << "Quartos: " << imovel.quartos << endl;
        out << "Banheiros: " << imovel.banheiros << endl;

        switch (imovel.tipo) {
            case TipoImovel::CASA:
                out << "Casa" << endl;
                break;
            case TipoImovel::APARTAMENTO:
                out << "Apartamento" << endl;
                break;
            case TipoImovel::CHACARA:
                out << "Chacara" << endl;
                break;
        }

        return out;
    }
};