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

    friend ostream& operator<<(ostream& out, const Casa& casa) {
        out << static_cast<const Imovel&>(casa);
        // imprime os atributos adicionais da classe Casa
        return out;
    }
};
