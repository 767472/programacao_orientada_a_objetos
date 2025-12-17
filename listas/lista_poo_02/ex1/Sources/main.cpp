#include <iostream>
#include <vector>
#include <memory>  

#include "Funcionario.h"
#include "Assalariado.h" 
#include "Horista.h"      
#include "Comissionado.h" 

int main() {
    std::vector<std::unique_ptr<Funcionario>> Pagamentos;
    Pagamentos.emplace_back( std::make_unique<Assalariado>(101, "Ana Silva", "111.222.333-44", 5000.00));
    Pagamentos.emplace_back( std::make_unique<Horista>(202, "Bruno Costa", "555.666.777-88", 50.00, 50.00) );
    Pagamentos.emplace_back( std::make_unique<Comissionado>(303, "Carla Meirelles", "999.000.111-22", 1500.00, 10000.00, 10.0)
    );
    double totalFolha = 0.0;
    
    std::cout << "\n--- Processamento da Folha de Pagamento ---\n";
    
    for (const auto& func : Pagamentos) {
        double pagamento = func->calcularPagamento();
        totalFolha += pagamento;
        std::cout << func->MostrarDados() << "\n";
    }

    std::cout << "--------------------------------------------------------------------------\n";
    std::cout << "TOTAL GERAL DA FOLHA DE PAGAMENTO: R$ " << totalFolha << "\n";
    std::cout << "--------------------------------------------------------------------------\n\n";
    return 0;
}