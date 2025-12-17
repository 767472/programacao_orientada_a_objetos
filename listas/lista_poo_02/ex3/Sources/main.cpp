#include <vector>
#include <memory>
#include "Carro.h"
#include "Caminhao.h"
#include "Onibus.h"

int main() {
    // Coleção heterogênea de veículos.
    std::vector<std::unique_ptr<VeiculoAutonomo>> frota;

    frota.emplace_back(new CarroAutonomo(1, 4));
    frota.emplace_back(new CaminhaoAutonomo(2, 18.5, 6)); // Carga: 18.5 t.
    frota.emplace_back(new OnibusAutonomo(3, 40, true)); // Capacidade: 40 lugares (acessível).

    std::cout << "--- Operacao da Frota Autonoma ---\n\n";

    for (const auto& veiculo : frota) {
        veiculo->relatorioStatus();
        veiculo->detectarObstaculos(); // Detecção por sensor (polimórfico).
        veiculo->mover();              // Movimentação (polimórfica).
        
        // Simula necessidade de recarga.
        veiculo->recarregar(); 
        std::cout << "--------------------------------\n";
    }

    return 0;
}