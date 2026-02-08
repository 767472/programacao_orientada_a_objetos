#include <vector>
#include <memory>
#include "Circulo.h"
#include "Retangulo.h"
#include "Poligono.h"

int main() {
    std::vector<std::unique_ptr<Forma>> canvas;

    // Adiciona formas ao conjunto.
    canvas.emplace_back(new Circulo(0, 0, 5.0));
    canvas.emplace_back(new Retangulo(10, 10, 4.0, 2.0));

    // Cria um triângulo.
    std::vector<Ponto> tri = {{0,0}, {5,0}, {2.5, 5}};
    canvas.emplace_back(new Poligono(20, 20, tri));

    std::cout << "--- Renderizando e Movendo ---\n";
    
    for(const auto& f : canvas) {
        f->desenhar();
        std::cout << "Area: " << f->area() << "\n";
        
        // Movimento polimórfico.
        f->mover(2.0, 2.0); 
        
        std::cout << "\n";
    }

    return 0;
}