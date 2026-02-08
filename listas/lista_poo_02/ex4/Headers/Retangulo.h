#ifndef RETANGULO_H
#define RETANGULO_H

#include "Forma.h"

class Retangulo : public Forma {
private:
    double largura;
    double altura;

public:
    Retangulo(double x, double y, double largura, double altura);
    ~Retangulo() override;

    void desenhar() const override;
    double area() const override;
    double perimetro() const override;
    Retangulo* clonar() const override;
};

#endif