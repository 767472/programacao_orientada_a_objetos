#include "Poligono.h"
#include <cmath>

Poligono::Poligono(double x, double y, const std::vector<Ponto>& vertices)
    : Forma(x, y), vertices(vertices) {}

Poligono::~Poligono() {}

void Poligono::desenhar() const {
    std::cout << "Desenhando Poligono [Ancora: (" << x << "," << y 
              << "), " << vertices.size() << " vertices]\n";
    for(size_t i = 0; i < vertices.size(); i++) {
        std::cout << "   V" << i << ": (" << vertices[i].x << ", " << vertices[i].y << ")\n";
    }
}

double Poligono::area() const {
    // Cálculo não implementado (retorna zero para exemplo).
    return 0.0; 
}

double Poligono::perimetro() const {
    // Retorna zero para simplificação.
    return 0.0; 
}

Poligono* Poligono::clonar() const {
    return new Poligono(*this);
}

void Poligono::mover(double dx, double dy) {
    // Chama a implementação base para mover a âncora.
    Forma::mover(dx, dy);
    
    // Atualiza as posições dos vértices.
    for(auto& p : vertices) {
        p.x += dx;
        p.y += dy;
    }
}