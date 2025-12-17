#ifndef HORISTA_H
#define HORISTA_H

#include "Funcionario.h" 
#include <iostream>
#include <string>

class Horista final : public Funcionario {
private:
    double valorHora_;
    double QuantidadeHoras_;

public:
    // Construtor.
    Horista(int id, const std::string& nome, const std::string& cpf, double valorHora, double QuantidadeHoras)
        : Funcionario(id, nome, cpf), valorHora_(valorHora), QuantidadeHoras_(QuantidadeHoras) {
          std::cout << "Horista: Objeto derivado CRIADO \n";
         }
    ~Horista() override {
    // Destrutor.
        std::cout << " Horista: Objeto derivado DESTRUÍDO .\n";
    }

    // Declaração da função virtual pura (Implementação em cpp).
    double calcularPagamento() const override;
    

    // Declaração do método MostrarDados (Implementação em cpp).
    std::string MostrarDados() const override;
};

#endif