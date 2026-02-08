#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "Veiculo.h"

class CaminhaoAutonomo : public VeiculoAutonomo {
private:
    double carga; // Carga em toneladas.
    int eixos;

public:
    CaminhaoAutonomo(int id, double carga, int eixos);
    ~CaminhaoAutonomo() override;

    void mover() override;
    void detectarObstaculos() const override;
    void recarregar() override; // Recarrega (implementação específica para caminhão).
    void relatorioStatus() const override;
};

#endif