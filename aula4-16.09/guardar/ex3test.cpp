#include <iostream>
#include <string>
#include <vector>
using namespace std;

// =================== Classe Produto ===================
class Produto {
private:
    string nome;
    double preco;
public:
    Produto(string n, double p) : nome(n), preco(p) {}

    string getNome() const { return nome; }
    double getPreco() const { return preco; }
};

// =================== Classe Cliente ===================
class Cliente {
private:
    string nome;
    string email;
public:
    Cliente(string n, string e) : nome(n), email(e) {}

    string getNome() const { return nome; }
    string getEmail() const { return email; }
};

// =================== Classe ItemPedido ===================
class ItemPedido {
private:
    Produto produto;
    int quantidade;
public:
    ItemPedido(Produto p, int q) : produto(p), quantidade(q) {}

    double getSubtotal() const {
        return produto.getPreco() * quantidade;
    }

    void mostrarItem() const {
        cout << quantidade << "x " << produto.getNome()
             << " - R$ " << produto.getPreco()
             << " = R$ " << getSubtotal() << endl;
    }
};

// =================== Classe Pedido ===================
class Pedido {
private:
    Cliente cliente;
    vector<ItemPedido> itens;
public:
    Pedido(Cliente c) : cliente(c) {}

    void adicionarItem(Produto p, int qtd) {
        itens.push_back(ItemPedido(p, qtd));
    }

    double calcularTotal() const {
        double total = 0;
        for (const auto& item : itens) {
            total += item.getSubtotal();
        }
        return total;
    }

    void mostrarPedido() const {
        cout << "Cliente: " << cliente.getNome()
             << " (" << cliente.getEmail() << ")" << endl;
        cout << "Itens do pedido:" << endl;
        for (const auto& item : itens) {
            item.mostrarItem();
        }
        cout << "TOTAL = R$ " << calcularTotal() << endl;
    }
};

// =================== Programa principal ===================
int main() {
    // Criando cliente
    Cliente cliente("Joao Silva", "joao@email.com");

    // Criando produtos
    Produto p1("Notebook", 3500.00);
    Produto p2("Mouse Gamer", 150.00);
    Produto p3("Teclado Mecânico", 420.00);

    // Criando pedido
    Pedido pedido(cliente);
    pedido.adicionarItem(p1, 1);
    pedido.adicionarItem(p2, 2);
    pedido.adicionarItem(p3, 1);

    // Mostrar pedido
    pedido.mostrarPedido();

    return 0;
}
