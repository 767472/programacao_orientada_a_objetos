#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Parada {
private:
    string nome, endereco;
public:
    Parada(const string& n, const string& e) : nome(n), endereco(e){
        cout << "Parada: " << nome << " criada\n";
    }
    ~Parada(){ cout << "Parada: " << nome << " destruida\n"; }
    string info() const { return nome + " - " + endereco; }
};

class Rota {
private:
    string codigo;
    vector<Parada> paradas;
public:
    Rota(const string& c) : codigo(c){ cout << "Rota: " << codigo << " criada\n"; }
    ~Rota(){ cout << "Rota: " << codigo << " destruida\n"; }
    void adicionar(const Parada& p){ paradas.push_back(p); }
    string getCodigo() const { return codigo; }
    void listar() const{
        cout << "Rota " << codigo << ":\n";
        for (auto& p : paradas) cout << " - " << p.info() << "\n";
    }
};

class Motorista {
private:
    string nome, cnh;
public:
    Motorista(const string& n, const string& c) : nome(n), cnh(c){
        cout << "Motorista: " << nome << " criado\n";
    }
    ~Motorista(){ cout << "Motorista: " << nome << " destruido\n"; }
    string getNome() const { return nome; }
};

class Onibus {
private:
    string placa;
    int capacidade;
    Rota* rota;
public:
    Onibus(const string& p, int cap) : placa(p), capacidade(cap), rota(nullptr){
        cout << "Onibus: " << placa << " criado\n";
    }
    ~Onibus(){ cout << "Onibus: " << placa << " destruido\n"; }
    void setRota(Rota* r){ rota = r; }
    void info() const{
        cout << "Onibus " << placa << " cap=" << capacidade
             << " rota=" << (rota ? rota->getCodigo() : "sem rota") << "\n";
    }
};

class Empresa {
private:
    string nome;
    vector<Onibus> frota;
    vector<Motorista*> motoristas;
public:
    Empresa(const string& n) : nome(n){ cout << "Empresa: " << nome << " criada\n"; }
    ~Empresa(){ cout << "Empresa: " << nome << " destruida\n"; }
    void contratar(Motorista* m){ motoristas.push_back(m); }
    void comprar(const Onibus& o){ frota.push_back(o); }
    void listar() const{
        cout << "Empresa " << nome << "\n";
        cout << "Motoristas:\n";
        for (auto* m : motoristas) cout << " - " << m->getNome() << "\n";
        cout << "Frota:\n";
        for (auto& o : frota) o.info();
    }
};

int main(){
    Rota r("R1");
    r.adicionar(Parada("Terminal", "Centro"));
    r.adicionar(Parada("UFMS", "Av. B"));

    Onibus o1("ABC-1234", 40);
    o1.setRota(&r);

    Motorista m("Carlos", "999999");

    Empresa e("TransMS");
    e.comprar(o1);
    e.contratar(&m);

    r.listar();
    e.listar();
    return 0;
}
