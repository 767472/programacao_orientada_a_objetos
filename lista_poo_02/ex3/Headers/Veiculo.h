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
    virtual void recarregar(); // Estrategia padrao
    
    // Metodo de sensor pedido no exercicio
    virtual void detectarObstaculos() const = 0;
};

#endif