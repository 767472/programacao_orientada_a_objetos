#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Produto {
private:
    string nome; double preco;
public:
    Produto(const string& n, double p) : nome(n), preco(p){
        cout << "Produto: " << nome << " criado\n";
    }
    ~Produto(){ cout << "Produto: " << nome << " destruido\n"; }
    string getNome() const { return nome; }
    double getPreco() const { return preco; }
};

class ItemCarrinho {
private:
    Produto* produto; int qtd;
public:
    ItemCarrinho(Produto* p, int q) : produto(p), qtd(q){
        cout << "ItemCarrinho: " << (p ? p->getNome() : \"?\") << \" criado\n\";
    }
    ~ItemCarrinho(){ cout << \"ItemCarrinho destruido\n\"; }
    double subtotal() const { return (produto ? produto->getPreco() : 0.0) * qtd; }
    string info() const {
        return (produto ? produto->getNome() : \"?\") + string(\" x\") + to_string(qtd) +
               \" = \" + to_string(subtotal());
    }
};

class Carrinho {
private:
    vector<ItemCarrinho> itens;
public:
    Carrinho(){ cout << "Carrinho criado\n"; }
    ~Carrinho(){ cout << "Carrinho destruido\n"; }
    void add(const ItemCarrinho& it){ itens.push_back(it); }
    double total() const { double t=0; for (auto& i : itens) t+=i.subtotal(); return t; }
    void listar() const { for (auto& i : itens) cout << " - " << i.info() << "\n"; }
};

class Pagamento {
private:
    string modo, status;
public:
    Pagamento(const string& m) : modo(m), status("pendente"){
        cout << "Pagamento: " << modo << " criado\n";
    }
    ~Pagamento(){ cout << "Pagamento: " << modo << " destruido\n"; }
    void aprovar(){ status = "aprovado"; }
    void reprovar(){ status = "reprovado"; }
    string getStatus() const { return status; }
};

class Pedido {
private:
    int numero;
    Carrinho carrinho;
    Pagamento pagamento;
public:
    Pedido(int num, const string& modoPgto)
        : numero(num), carrinho(), pagamento(modoPgto) {
        cout << "Pedido #" << numero << " criado\n";
    }
    ~Pedido(){ cout << "Pedido #" << numero << " destruido\n"; }
    Carrinho& getCarrinho(){ return carrinho; }
    Pagamento& getPagamento(){ return pagamento; }
    void fechar(bool aprovar){
        if (aprovar) pagamento.aprovar(); else pagamento.reprovar();
        cout << "Pedido #" << numero << " total=" << carrinho.total()
             << " status=" << pagamento.getStatus() << "\n";
    }
};

int main(){
    Produto p1("Livro", 80.0), p2("Headset", 250.0);

    Pedido ped(5001, "pix");
    ped.getCarrinho().add(ItemCarrinho(&p1, 2));
    ped.getCarrinho().add(ItemCarrinho(&p2, 1));

    ped.getCarrinho().listar();
    ped.fechar(true); 
    return 0;
}
