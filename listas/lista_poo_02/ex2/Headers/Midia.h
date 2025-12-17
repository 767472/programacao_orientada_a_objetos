#ifndef MIDIA_H
#define MIDIA_H

#include <string>
#include <iostream>

class Midia {
protected:
    std::string titulo;
    int ano;
    double duracao;

public:
    Midia(std::string titulo, int ano, double duracao);
    virtual ~Midia();

    virtual void reproduzir() const = 0;
    virtual void infoDetalhada() const;
    
    // Método de busca polimórfico (filtro).
    virtual bool combina(std::string termo) const;
};

#endif