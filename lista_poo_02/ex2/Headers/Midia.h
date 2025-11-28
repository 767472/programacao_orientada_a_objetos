#ifndef MIDIA_H
#define MIDIA_H

#include <string>
#include <iostream>

class Midia {
protected:
    std::string titulo;
    int ano;
    double duracao; // em minutos

public:
    Midia(std::string titulo, int ano, double duracao);
    virtual ~Midia();

    virtual void reproduzir() const = 0;
    virtual void infoDetalhada() const;
    
    // Metodo de busca polimorfico (filtro)
    virtual bool combina(std::string termo) const;
};

#endif