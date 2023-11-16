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

    friend ostream& operator<<(ostream& out, const Chacara& chacara) {
        out << static_cast<const Imovel&>(chacara);
        // imprime os atributos adicionais da classe Chacara
        return out;
    }
};
