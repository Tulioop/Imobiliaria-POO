#ifndef APTO_H
#define APTO_H

#include "imovel.h"

class Apartamento : public Imovel {
private:
    int andar;
    float taxa_condominio;
    bool elevador;
    bool sacada;

public:
    // Métodos set
    void setAndar(int novoAndar);

    void setTaxaCondominio(float novaTaxa);

    void setElevador(bool novoElevador);

    void setSacada(bool novaSacada);

    // Métodos get
    int getAndar() const;

    float getTaxaCondominio() const;

    bool getElevador() const;

    bool getSacada() const;

    friend ostream& operator<<(ostream& out, const Apartamento& apartamento);
};

#endif