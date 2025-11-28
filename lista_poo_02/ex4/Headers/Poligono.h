#ifndef POLIGONO_H
#define POLIGONO_H

#include "Forma.h"
#include <vector>

struct Ponto {
    double x, y;
};

class Poligono : public Forma {
private:
    std::vector<Ponto> vertices;

public:
    Poligono(double x, double y, const std::vector<Ponto>& vertices);
    ~Poligono() override;

    void desenhar() const override;
    double area() const override;
    double perimetro() const override;
    Poligono* clonar() const override;

    // Sobrescreve mover para atualizar todos os vertices tambem
    void mover(double dx, double dy) override;
};

#endif