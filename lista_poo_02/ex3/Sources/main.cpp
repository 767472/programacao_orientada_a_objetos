#include <vector>
#include <memory>
#include "Carro.h"
#include "Caminhao.h"
#include "Onibus.h"

int main() {
    // Despachante: Colecao heterogenea
    std::vector<std::unique_ptr<VeiculoAutonomo>> frota;

    frota.emplace_back(new CarroAutonomo(1, 4));
    frota.emplace_back(new CaminhaoAutonomo(2, 18.5, 6)); // 18.5 toneladas
    frota.emplace_back(new OnibusAutonomo(3, 40, true)); // 40 lugares, acessivel

    std::cout << "--- Operacao da Frota Autonoma ---\n\n";

    for (const auto& veiculo : frota) {
        veiculo->relatorioStatus();
        veiculo->detectarObstaculos(); // Sensor polimorfico
        veiculo->mover();              // Movimento polimorfico
        
        // Simula necessidade de recarga
        veiculo->recarregar(); 
        std::cout << "--------------------------------\n";
    }

    return 0;
}