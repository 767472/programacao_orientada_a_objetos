#include "Forma.h"

Forma::Forma(double x, double y) : x(x), y(y) {}

Forma::~Forma() {}

void Forma::mover(double dx, double dy) {
    x += dx;
    y += dy;
    std::cout << "-> Forma movida para (" << x << ", " << y << ")\n";
}