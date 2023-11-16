#ifndef CHACARA_H
#define CHACARA_H

#include "imovel.h"

class Chacara : public Imovel {
private:
    bool salao_festa;
    bool salao_jogos;
    bool campo_futebol;
    bool churrasqueira;
    bool piscina;

public:
    // Métodos set
    void setSalaoFesta(bool novoSalaoFesta);

    void setSalaoJogos(bool novoSalaoJogos);

    void setCampoFutebol(bool novoCampoFutebol);

    void setChurrasqueira(bool novaChurrasqueira);

    void setPiscina(bool novaPiscina);

    // Métodos get
    bool getSalaoFesta() const;

    bool getSalaoJogos() const;

    bool getCampoFutebol() const;

    bool getChurrasqueira() const;

    bool getPiscina() const;

    friend ostream& operator<<(ostream& out, const Chacara& chacara);
};
#endif