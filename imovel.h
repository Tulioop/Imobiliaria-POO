#ifndef IMOVEL_H
#define IMOVEL_H

#include <iostream>
#include <string>
#include <fstream>

enum class TipoImovel {
    CASA,
    APARTAMENTO,
    CHACARA
};

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
    TipoImovel tipo;

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

    TipoImovel setTipo();

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

    TipoImovel getTipo() const;
    
    friend ostream& operator<<(ostream& out, const Imovel& imovel);

    virtual ~Imovel() {}
    
    virtual void mostrarDados(ostream& out) const = 0;

    virtual void salvarDados(ofstream& arquivo) const = 0;
};

#endif