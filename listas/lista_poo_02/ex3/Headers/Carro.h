#ifndef CARRO_H
#define CARRO_H
#include "Veiculo.h"

class CarroAutonomo : public VeiculoAutonomo {
public:
    CarroAutonomo(int id);
    void mover() override;
    void detectarObstaculos() const override;
};
#endif