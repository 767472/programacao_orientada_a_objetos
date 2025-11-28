#ifndef ASSALARIADO_H
#define ASSALARIADO_H

#include "Funcionario.h" 
#include <iostream>
#include <string>

class Assalariado final : public Funcionario {
private:
    double salarioMensal_;

public:
    // Construtor
    Assalariado(int id, const std::string& nome, const std::string& cpf, double salarioMensal)
        : Funcionario(id, nome, cpf), salarioMensal_(salarioMensal) {
          std::cout << "Assalariado: Objeto derivado CRIADO \n";
         }
    ~Assalariado() override {
    // Destrutor
        std::cout << " Assalariado: Objeto derivado DESTRUÍDO .\n";
    }

    // Implementação da função virtual pura
    double calcularPagamento() const override {
        // o pagamento é simplesmente o salário fixo.
        return salarioMensal_;
    }

    // Mostrar Salario
    std::string MostrarDados() const override {
        std::string base = Funcionario::MostrarDados();
        return 
        base 
        + "\n | Tipo: Assalariado\n | Salário Fixo: R$ " 
        + std::to_string(salarioMensal_) + "\n";
    }
};

#endif