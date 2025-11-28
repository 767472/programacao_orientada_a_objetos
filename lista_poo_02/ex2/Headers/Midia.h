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
    // Construtor
    Midia(const std::string& titulo, int ano, double duracao)
        : titulo(titulo), ano(ano), duracao(duracao) {
      std::cout << "Midia ("<< titulo <<") CRIADA";
    }

    // Destrutor virtual
    virtual ~Midia() {
      std::cout << "Midia ("<< titulo <<") DESTRUIDA";
    } 

    // Metodos Virtuis Puros
    virtual void reproduzir() = 0; 
    virtual bool combina(const std::string& filtro) const = 0; 

    // Metodo Virtual
    virtual void infoDetalhada() const {
        std::cout << "Título: " << titulo << ", Ano: " << ano << ", Duração: " << duracao << "s\n";
    }
};

#endif