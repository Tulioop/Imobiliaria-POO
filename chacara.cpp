#include <iostream>
#include <string>

using namespace std;

class Chacara : public Imovel {
private:
    bool salao_festa;
    bool salao_jogos;
    bool campo_futebol;
    bool churrasqueira;
    bool piscina;

public:
    // Métodos set
    void setSalaoFesta(bool novoSalaoFesta) {
        salao_festa = novoSalaoFesta;
    }

    void setSalaoJogos(bool novoSalaoJogos) {
        salao_jogos = novoSalaoJogos;
    }

    void setCampoFutebol(bool novoCampoFutebol) {
        campo_futebol = novoCampoFutebol;
    }

    void setChurrasqueira(bool novaChurrasqueira) {
        churrasqueira = novaChurrasqueira;
    }

    void setPiscina(bool novaPiscina) {
        piscina = novaPiscina;
    }

    // Métodos get
    bool getSalaoFesta() const {
        return salao_festa;
    }

    bool getSalaoJogos() const {
        return salao_jogos;
    }

    bool getCampoFutebol() const {
        return campo_futebol;
    }

    bool getChurrasqueira() const {
        return churrasqueira;
    }

    bool getPiscina() const {
        return piscina;
    }

    virtual ~Imovel() {}

    virtual void mostrarDados(ostream& out) const override{
        printInfo(out);
    }
    
    virtual void salvarDados(ofstream& arquivo) const override{
        arquivo << static_cast<const Imovel&>(apartamento);
        if (chacara.salao_festa == 1) arquivo << "Possui Salão de Festas" <<endl;
        if (chacara.salao_jogos == 1) arquivo << "Possui Salão de Jogos" <<endl;
        if (chacara.campo.futebol == 1) arquivo << "Possui Campo de Futebol" <<endl;
        if (chacara.churrasqueira == 1) arquivo << "Possui Churrasqueira" <<endl;
        if (chacara.piscina == 1) arquivo << "Possui Piscina" <<endl;
    }

    friend ostream& operator<<(ostream& out, const Chacara& chacara) {
        out << static_cast<const Imovel&>(chacara);
        if (chacara.salao_festa == 1) out << "Possui Salão de Festas" <<endl;
        if (chacara.salao_jogos == 1) out << "Possui Salão de Jogos" <<endl;
        if (chacara.campo.futebol == 1) out << "Possui Campo de Futebol" <<endl;
        if (chacara.churrasqueira == 1) out << "Possui Churrasqueira" <<endl;
        if (chacara.piscina == 1) out << "Possui Piscina" <<endl;
        return out;
    }
};
