#include "Comissionado.h"
#include <string>
#include <iostream>
#include <sstream>

double Comissionado::calcularPagamento() const {  
    // Comissão = Vendas * (Percentual / 100).
    double valorComissao = vendasTotais_ * (Comissao_ / 100.0);
    return salarioBase_ + valorComissao;
}

std::string Comissionado::MostrarDados() const {
    std::string base = Funcionario::MostrarDados(); 
    double pagamento = calcularPagamento(); 
    double comissaoPaga = vendasTotais_ * (Comissao_ / 100.0);
    return base  
           + "\n | Tipo: Comissionado \n | Base Salarial: R$ " + std::to_string(salarioBase_)
           + "\n | Vendas Totais: R$ " + std::to_string(vendasTotais_)
           + "\n | Comissão: " + std::to_string(Comissao_) + "%"
           + "\n | Comissão Paga: R$ " + std::to_string(comissaoPaga)
           + "\n | Salario Total: R$ " + std::to_string(pagamento)
           + "\n";
}