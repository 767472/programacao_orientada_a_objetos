#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Cliente { // Relação de agregação com Pedidos
private:
    string nome;
    string email;
public:
    Cliente(string n, string e) : nome(n), email(e) {
      cout << "Cliente "<< nome <<" Criado\n";
    }
    ~Cliente() {
      cout << "Cliente "<< nome <<" Destruido\n";
    }

    string getNome() const { return nome; }
    string getEmail() const { return email; }
};

class ItemPedido { // Relação composição com pedidos
private:
    string nomePro;
    double precoUni;
    int quant;
public:
    ItemPedido(string n, double p, int q): nomePro(n), precoUni(p), quant(q) {
      cout << "Itempedido "<< nomePro <<" Criado\n";
    }
    ~ItemPedido(){
      cout << "Itempedido "<< nomePro <<" destruido\n";
    }

    double subtotal() const {
        return precoUni * quant;
    }

    void mostrarItem() const {
        cout << quant << "x " << nomePro << " - R$ " << precoUni << " = R$ " << subtotal() <<"\n";
    }
};

class Pedido {
private:
    Cliente cliente;
    vector<ItemPedido> itens;
public:
    Pedido(Cliente c) : cliente(c) {}

    void addItem(string nomePro, double preco, int qtd) {
        itens.push_back(ItemPedido(nomePro, preco, qtd));
    }

    double calTotal() const {
        double total = 0;
        for (const auto& item : itens) {
            total += item.subtotal();
        }
        return total;
    }

    void mostrarPedido() const {
        cout << "Cliente: " << cliente.getNome() << " (" << cliente.getEmail() << ") \n";
        cout << "Itens do pedido: \n";
        for (const auto& item : itens) {
            item.mostrarItem();
        }
        cout << "TOTAL = R$ " << calTotal() << "\n";
    }
};

int main() {
    cout << "\nCriando cliente\n";
    Cliente cliente("Maria Souza", "maria@email.com");

    cout << "\nCriando pedido\n";
    Pedido pedido(cliente);
    pedido.addItem("Notebook", 3500.00, 1);
    pedido.addItem("Mouse Gamer", 150.00, 2);
    pedido.addItem("Teclado Mecânico", 420.00, 1);

    cout << "\nMostrar pedido\n";
    pedido.mostrarPedido();

    return 0;
}
