#include "Horista.h"
#include <string>
#include <iostream>

const double Horas_regulares = 44.0;
const double Porcentagem_extra = 1.5; 

double Horista::calcularPagamento() const {
    if (QuantidadeHoras_ <= Horas_regulares) {
        return QuantidadeHoras_ * valorHora_;
    } else {
        double pagamentoRegular = Horas_regulares * valorHora_;
        double horasExtras = QuantidadeHoras_ - Horas_regulares;
        double pagamentoExtra = horasExtras * valorHora_ * Porcentagem_extra;
        return pagamentoRegular + pagamentoExtra;
    }
}

std::string Horista::MostrarDados() const {
    std::string base = Funcionario::MostrarDados();
    double pagamento = calcularPagamento();
    const double HORAS_REGULARES = 44.0;
    double horasExtras = 0.0;
    if (QuantidadeHoras_ > HORAS_REGULARES) {
        horasExtras = QuantidadeHoras_ - HORAS_REGULARES;
    }
    return base + 
    "\n | Tipo: Horista " +
    "\n | Quantidade de Horas: " + std::to_string(QuantidadeHoras_) +
    "\n | HorasExtras: " + std::to_string(horasExtras) +
    "\n | Salario Total: R$" + std::to_string(pagamento) +
    "\n";
}