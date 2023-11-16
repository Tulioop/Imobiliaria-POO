#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>

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
    void setId(int newId);

    void setValor(float newValue);

    void setProprietario(string newProprietario);

    void setRua(string newRua);

    void setBairro(string newBairro);

    void setCidade(string newCidade);

    void setNumero(int newNumero);

    void setQuartos(int newQuartos);

    void setBanheiros(int newBanheiros);

    // Métodos get
    int getId() const;

    float getValor() const;

    string getProprietario() const;

    string getRua() const;

    string getBairro() const;

    string getCidade() const;

    int getNumero() const;

    int getQuartos() const;

    int getBanheiros() const;
    
    friend ostream& operator<<(ostream& out, const Imovel& imovel);
};

#endif