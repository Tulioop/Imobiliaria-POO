#ifndef CASA_H
#define CASA_H

#include "imovel.h"

class Casa : public Imovel
{
private:
    int andares;
    bool sala_jantar;

public:
    // Métodos set
    void setAndares(int novosAndares);

    void setSalaJantar(bool novaSalaJantar);

    // Métodos get
    int getAndares() const;

    bool getSalaJantar() const;

    friend ostream &operator<<(ostream &out, const Casa &casa);

    virtual ~Imovel() {}
    
    virtual void mostrarDados(ostream& out) const = 0;

    virtual void salvarDados(ofstream& arquivo) const = 0;
};

#endif