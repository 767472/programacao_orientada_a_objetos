#include "Caminhao.h"

CaminhaoAutonomo::CaminhaoAutonomo(int id, double carga, int eixos)
    : VeiculoAutonomo(id), carga(carga), eixos(eixos) {}

CaminhaoAutonomo::~CaminhaoAutonomo() {}

void CaminhaoAutonomo::mover() {
    std::cout << "[Caminhao " << id << "] Rota de carga pesada (evitando pontes fracas)...\n";
    bateria -= 12.0;
}

void CaminhaoAutonomo::detectarObstaculos() const {
    std::cout << "[Sensor Caminhao] Radar de longo alcance verificando rodovia.\n";
}

void CaminhaoAutonomo::recarregar() {
    std::cout << "Veiculo " << id << " acoplando em doca de recarga de alta voltagem.\n";
    bateria = 100.0;
}

void CaminhaoAutonomo::relatorioStatus() const {
    VeiculoAutonomo::relatorioStatus();
    std::cout << " | Tipo: Caminhao | Carga: " << carga << "T (" << eixos << " eixos)\n";
}