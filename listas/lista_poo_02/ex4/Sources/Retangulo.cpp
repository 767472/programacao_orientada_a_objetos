#include "Retangulo.h"
#include <stdexcept>

Retangulo::Retangulo(double x, double y, double largura, double altura)
    : Forma(x, y), largura(largura), altura(altura) {
    if (largura <= 0 || altura <= 0) {
        throw std::invalid_argument("Erro: Dimensoes devem ser positivas.");
    }
}

Retangulo::~Retangulo() {}

void Retangulo::desenhar() const {
    std::cout << "Desenhando Retangulo [Origem: (" << x << "," << y 
              << "), L: " << largura << ", A: " << altura << "]\n";
}

double Retangulo::area() const {
    return largura * altura;
}

double Retangulo::perimetro() const {
    return 2 * (largura + altura);
}

Retangulo* Retangulo::clonar() const {
    return new Retangulo(*this);
}