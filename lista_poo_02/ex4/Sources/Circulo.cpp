#include "Circulo.h"
#include <cmath>

Circulo::Circulo(double x, double y, double raio) : Forma(x, y), raio(raio) {
    if (raio <= 0) {
        throw std::invalid_argument("Erro: O raio deve ser maior que zero.");
    }
}

Circulo::~Circulo() {}

void Circulo::desenhar() const {
    std::cout << "Desenhando Circulo [Centro: (" << x << "," << y 
              << "), Raio: " << raio << "]\n";
}

double Circulo::area() const {
    return 3.14159 * raio * raio;
}

double Circulo::perimetro() const {
    return 2 * 3.14159 * raio;
}

Circulo* Circulo::clonar() const {
    return new Circulo(*this); // Cria uma copia exata
}