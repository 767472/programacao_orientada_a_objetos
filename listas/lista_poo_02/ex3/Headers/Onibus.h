#ifndef ONIBUS_H
#define ONIBUS_H

#include "Veiculo.h"

class OnibusAutonomo : public VeiculoAutonomo {
private:
    int lotacaoMaxima;
    bool acessibilidade;

public:
    OnibusAutonomo(int id, int lotacaoMaxima, bool acessibilidade);
    ~OnibusAutonomo() override;

    void mover() override;
    void detectarObstaculos() const override;
    void relatorioStatus() const override;
};

#endif