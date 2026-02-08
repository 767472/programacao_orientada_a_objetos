#ifndef COMISSIONADO_H
#define COMISSIONADO_H

#include "Funcionario.h"
#include <string>
#include <iostream>

class Comissionado final : public Funcionario {
private:
    double salarioBase_;
    double vendasTotais_;
    double Comissao_;

public:
    // Construtor.
    Comissionado(int id, const std::string& nome, const std::string& cpf,
                 double salarioBase, double vendasTotais, double Comissao)
        : Funcionario(id, nome, cpf), salarioBase_(salarioBase), vendasTotais_(vendasTotais), Comissao_(Comissao) {
        std::cout << " Comissionado (" << nome << "): Objeto CRIADO.\n";
    }

    // Destrutor.
    ~Comissionado() override {
        std::cout << " Comissionado: (" << nome << ") Objeto DESTRUÍDO.\n";
    }

    // Declaração (Implementação em .cpp).
    double calcularPagamento() const override;
    std::string MostrarDados() const override; 
};

#endif
#ifndef FORMA_H
#define FORMA_H

#include <iostream>

class Forma {
protected:
    double x, y; // Ponto de Origem.

public:
    Forma(double x, double y);
    virtual ~Forma();

    // Métodos puramente virtuais.
    virtual void desenhar() const = 0;
    virtual double area() const = 0;
    virtual double perimetro() const = 0;
    
    // Método para clonar o objeto.
    virtual Forma* clonar() const = 0;

    // Mover: Implementado na classe base; pode ser sobrescrito por derivados.
    virtual void mover(double dx, double dy);
};

#endif