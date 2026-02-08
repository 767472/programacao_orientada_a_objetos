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