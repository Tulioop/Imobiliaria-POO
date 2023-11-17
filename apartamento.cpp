#include <iostream>
#include <string>

using namespace std;

class Apartamento : public Imovel {
private:
    int andar;
    float taxa_condominio;
    bool elevador;
    bool sacada;

public:
    // Métodos set
    void setAndar(int novoAndar) {
        andar = novoAndar;
    }

    void setTaxaCondominio(float novaTaxa) {
        taxa_condominio = novaTaxa;
    }

    void setElevador(bool novoElevador) {
        elevador = novoElevador;
    }

    void setSacada(bool novaSacada) {
        sacada = novaSacada;
    }

    // Métodos get
    int getAndar() const {
        return andar;
    }

    float getTaxaCondominio() const {
        return taxa_condominio;
    }

    bool getElevador() const {
        return elevador;
    }

    bool getSacada() const {
        return sacada;
    }

    virtual ~Imovel() {}

    virtual void mostrarDados(ostream& out) const override{
        printInfo(out);
    }
    
    virtual void salvarDados(ofstream& arquivo) const override{
        arquivo << static_cast<const Imovel&>(apartamento);
        arquivo << "Qtde Andar: " << apartamento.andar << endl;
        arquivo << "Taxa Condomínio: " << apartamento.taxa_condominio << endl;
        if (apartamento.elevador == 1) arquivo << "Possui Elevador" <<endl;
        if (apartamento.sacada == 1) arquivo << "Possui Sacada" <<endl;
    }

    friend ostream& operator<<(ostream& out, const Apartamento& apartamento) {
        out << static_cast<const Imovel&>(apartamento);
        out << "Qtde Andar: " << apartamento.andar << endl;
        out << "Taxa Condomínio: " << apartamento.taxa_condominio << endl;
        if (apartamento.elevador == 1) out << "Possui Elevador" <<endl;
        if (apartamento.sacada == 1) out << "Possui Sacada" <<endl;
        return out;
    }
};
