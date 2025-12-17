#include "Veiculo.h"

VeiculoAutonomo::VeiculoAutonomo(int id) : id(id), bateria(100.0) {}
VeiculoAutonomo::~VeiculoAutonomo() {}

void VeiculoAutonomo::relatorioStatus() const {
    std::cout << "ID: " << id << " | Bateria: " << bateria << "%\n";
}

void VeiculoAutonomo::recarregar() {
    std::cout << "Veiculo " << id << " carregando na estacao padrao.\n";
    bateria = 100;
}