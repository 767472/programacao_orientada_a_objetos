#include "Onibus.h"

OnibusAutonomo::OnibusAutonomo(int id, int p) : VeiculoAutonomo(id), passageiros(p) {}

void OnibusAutonomo::mover() {
    std::cout << "[Onibus " << id << "] Seguindo rota fixa com paradas.\n";
    bateria -= 8;
}

void OnibusAutonomo::detectarObstaculos() const {
    std::cout << "[Onibus] Sensores laterais ativos para paradas.\n";
}

void OnibusAutonomo::recarregar() {
    std::cout << "Onibus " << id << " recarregando rapido no Terminal Central.\n";
    bateria = 100;
}

void OnibusAutonomo::relatorioStatus() const {
    VeiculoAutonomo::relatorioStatus();
    std::cout << "   -> Passageiros a bordo: " << passageiros << "\n";
}