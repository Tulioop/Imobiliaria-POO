#include <iostream>
#include <string>

using namespace std;

class Casa : public Imovel {
private:
    int andares;
    bool sala_jantar;

public:
    // Métodos set
    void setAndares(int novosAndares) {
        andares = novosAndares;
    }

    void setSalaJantar(bool novaSalaJantar) {
        sala_jantar = novaSalaJantar;
    }

    // Métodos get
    int getAndares() const {
        return andares;
    }

    bool getSalaJantar() const {
        return sala_jantar;
    }

    virtual ~Imovel() {}

    virtual void mostrarDados(ostream& out) const override{
        printInfo(out);
    }
    
    virtual void salvarDados(ofstream& arquivo) const override{
        arquivo << static_cast<const Imovel&>(apartamento);
        arquivo << "Qtde de Andar: " << casa.andares << endl;
        if (casa.sala_jantar == 1) arquivo << "Possui Sala de Jantar" <<endl;
    }

    friend ostream& operator<<(ostream& out, const Casa& casa) {
        out << static_cast<const Imovel&>(casa);
        out << "Qtde de Andar: " << casa.andares << endl;
        if (casa.sala_jantar == 1) out << "Possui Sala de Jantar" <<endl;
        return out;
    }
};
