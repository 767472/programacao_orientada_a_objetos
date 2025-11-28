#include <vector>
#include <memory>
#include "Circulo.h"
#include "Retangulo.h"
#include "Poligono.h"

int main() {
    std::vector<std::unique_ptr<Forma>> canvas;

    try {
        // Adiciona formas
        canvas.emplace_back(new Circulo(0, 0, 5.0));
        canvas.emplace_back(new Retangulo(10, 10, 4.0, 2.0));

        // Cria poligono (Triangulo)
        std::vector<Ponto> tri = {{0,0}, {5,0}, {2.5, 5}};
        canvas.emplace_back(new Poligono(20, 20, tri));

        // Teste de validacao 
        canvas.emplace_back(new Circulo(0, 0, -5)); 

        std::cout << "--- Renderizando e Movendo ---\n";
        
        for(const auto& f : canvas) {
            f->desenhar();
            std::cout << "Area: " << f->area() << "\n";
            
            // Movimento polimorfico
            f->mover(2.0, 2.0); 
            
            std::cout << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Excecao capturada: " << e.what() << "\n";
    }

    return 0;
}