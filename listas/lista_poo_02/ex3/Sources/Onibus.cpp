#include "Onibus.h"

OnibusAutonomo::OnibusAutonomo(int id, int lotacaoMaxima, bool acessibilidade)
    : VeiculoAutonomo(id), lotacaoMaxima(lotacaoMaxima), acessibilidade(acessibilidade) {}

OnibusAutonomo::~OnibusAutonomo() {}

void OnibusAutonomo::mover() {
    std::cout << "[Onibus " << id << "] Priorizando faixas exclusivas e paradas agendadas.\n";
    bateria -= 8.0;
}

void OnibusAutonomo::detectarObstaculos() const {
    std::cout << "[Sensor Onibus] Verificando movimento nas portas de embarque.\n";
}

void OnibusAutonomo::relatorioStatus() const {
    VeiculoAutonomo::relatorioStatus();
    std::cout << " | Tipo: Onibus | Lotacao: " << lotacaoMaxima 
              << " | Acessivel: " << (acessibilidade ? "Sim" : "Nao") << "\n";
}