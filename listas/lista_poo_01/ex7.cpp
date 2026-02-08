#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Arma {
private:
    string nome; int dano;
public:
    Arma(const string& n, int d) : nome(n), dano(d){
        cout << "Arma: " << nome << " criada\n";
    }
    ~Arma(){ cout << "Arma: " << nome << " destruida\n"; }
    string getNome() const { return nome; }
    int getDano() const { return dano; }
};

class Item {
private:
    string nome; double peso;
public:
    Item(const string& n, double p) : nome(n), peso(p){
        cout << "Item: " << nome << " criado\n";
    }
    ~Item(){ cout << "Item: " << nome << " destruido\n"; }
    string info() const { return nome + " (" + to_string(peso) + "kg)"; }
};

class Inventario {
private:
    vector<Item> itens;
    vector<Arma> armas;
public:
    Inventario(){ cout << "Inventario criado\n"; }
    ~Inventario(){ cout << "Inventario destruido\n"; }
    void addItem(const Item& i){ itens.push_back(i); }
    void addArma(const Arma& a){ armas.push_back(a); }
    void listar() const{
        cout << "Itens:\n"; for (auto& i : itens) cout << " - " << i.info() << "\n";
        cout << "Armas:\n"; for (auto& a : armas) cout << " - " << a.getNome() << "\n";
    }
};

class Jogador {
private:
    string apelido;
    Inventario inv;
public:
    Jogador(const string& a) : apelido(a){ cout << "Jogador: " << apelido << " criado\n"; }
    ~Jogador(){ cout << "Jogador: " << apelido << " destruido\n"; }
    Inventario& inventario(){ return inv; }
};

class Inimigo {
private:
    string tipo; int hp;
    Arma* arma;
public:
    Inimigo(const string& t, int h) : tipo(t), hp(h), arma(nullptr){
        cout << "Inimigo: " << tipo << " criado\n";
    }
    ~Inimigo(){ cout << "Inimigo: " << tipo << " destruido\n"; }
    void equipar(Arma* a){ arma = a; }
    void status() const{
        cout << "Inimigo " << tipo << " HP=" << hp
             << " Arma=" << (arma ? arma->getNome() : "nenhuma") << "\n";
    }
};

int main(){
    Jogador j("Fabi");
    j.inventario().addItem(Item("Pocao", 0.5));
    j.inventario().addArma(Arma("Espada", 15));
    j.inventario().listar();

    Arma garra("Garras", 8);
    Inimigo lobo("Lobo", 30);
    lobo.equipar(&garra);
    lobo.status();
    return 0;
}
