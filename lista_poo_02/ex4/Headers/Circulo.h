#ifndef CIRCULO_H
#define CIRCULO_H

#include "Forma.h"
#include <stdexcept> // Para validacao

class Circulo : public Forma {
private:
    double raio;

public:
    Circulo(double x, double y, double raio);
    ~Circulo() override;

    void desenhar() const override;
    double area() const override;
    double perimetro() const override;
    
    // Retorno covariante (retorna Circulo* em vez de Forma*)
    Circulo* clonar() const override; 
};

#endif