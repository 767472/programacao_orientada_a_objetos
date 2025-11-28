#ifndef FORMA_H
#define FORMA_H

#include <iostream>

class Forma {
protected:
    double x, y; // Ponto de origem/ancora

public:
    Forma(double x, double y);
    virtual ~Forma();

    // Metodos puramente virtuais
    virtual void desenhar() const = 0;
    virtual double area() const = 0;
    virtual double perimetro() const = 0;
    
    // Metodo para clonar o objeto (Prototype Pattern)
    virtual Forma* clonar() const = 0;

    // Mover: Implementado na base, mas virtual caso Poligono precise mudar
    virtual void mover(double dx, double dy);
};

#endif