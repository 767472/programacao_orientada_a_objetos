#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include <string>

class Funcionario {
protected:
    int id;
    std::string nome;
    std::string cpf; 

public:
    // Construtor
    Funcionario(int id, const std::string& nome, const std::string& cpf)
        : id(id), nome(nome), cpf(cpf) {
          std::cout << "Funcionario (" << nome << "): CRIADO.\n ";
        }

    // Destrutor 
    virtual ~Funcionario() {
      std::cout << "Funcionario (" << nome << "): DESTRUIDO.\n ";
    }

    // Método abstrato (virtual puro)
    virtual double calcularPagamento() const = 0; 

    // Método virtual para mostrar dados da classe
    virtual std::string MostrarDados() const {
        return "ID: " + std::to_string(id) + " | Nome: " + nome;
    }
    
    // Getters
    std::string getNome() const { return nome; }
};

#endif