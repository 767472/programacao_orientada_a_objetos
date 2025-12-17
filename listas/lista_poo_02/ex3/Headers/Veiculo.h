#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>

class VeiculoAutonomo {
protected:
    int id;
    double bateria;

public:
    VeiculoAutonomo(int id);
    virtual ~VeiculoAutonomo();

    virtual void mover() = 0;
    virtual void relatorioStatus() const;
    virtual void recarregar(); // Estratégia de recarga padrão.
    
    // Método de sensor exigido pelo exercício.
    virtual void detectarObstaculos() const = 0;
};

#endif